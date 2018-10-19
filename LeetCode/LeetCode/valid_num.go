package main

import "fmt"

func isNumber(s string ) bool {
	s = trim(s)
	return isReal(s)
}

func isReal(s string) bool {
	if len(s) == 0	 {
		return false
	}

	if s[0] =='-' || s[0] =='+' {
		return isNonnegReal(s[1:], false)
	}

	return isNonnegReal(s, false)
}

func isNonnegReal(s string, hasDot bool) bool {
	if len(s) == 0	 {
		return false
	}

	for i, c := range s {
		switch {
		case '0' <=c && c<= '9':
			continue
		case c == '.':
			if hasDot {
				return false
			}

			if i == len(s)-1 && i != 0 {
				return true 
			}

			if i+1 < len(s) && s[i+1] == 'e' {
				return i != 0 && isInteger(s[i+2:])
			}

			return isNonnegReal(s[i+1:], true)
		case c == 'e':
			if i == 0 {
				return false
			}
			return isInteger(s[i+1:])
		default:
			return false
		}
	}
	return true
}

func isInteger(s string) bool {
	if len(s) == 0 {
		return false
	}

	if s[0] == '-' || s[0] == '+' {
		return isNonnegativeInteger(s[1:])
	}

	return isNonnegativeInteger(s)
}

func isNonnegativeInteger(s string) bool {
	if len(s) == 0 {
		return false
	}

	for _, c := range s {
		if c < '0' || '9' < c {
			return false
		}
	}

	return true
}

func trim(s string) string {
	i := 0
	for i < len(s) && s[i] == ' '	{
		i++
	}

	j := len(s) -1 
	for i <= j && s[j]== ' ' {
		j--
	}

	return s[i:j+1]
}

func main() {
	fmt.Println(isNumber("99"))
	fmt.Println(isNumber("-99"))
	fmt.Println(isNumber("+99"))
	fmt.Println(isNumber("a99"))
}
