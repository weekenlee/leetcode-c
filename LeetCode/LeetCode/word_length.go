package main

import "fmt"

func lengthOfLastWord(s string) int	 {
	size := len(s)
	if size == 0 {
		return 0
	}

	res := 0
	for i:=size-1; i >= 0 ; i-- {
		if s[i]==' ' {
			if res != 0 {
				return res
			}
			continue
		}

		res++
	}

	return res
}

func main() {
	fmt.Println(lengthOfLastWord("hello liweijian"))
}
