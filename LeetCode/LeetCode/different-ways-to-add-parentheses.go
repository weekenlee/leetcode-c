package main

import "fmt"
import "strconv"

func diffWaysToCompute(input string) []int {
	cache := make(map[string][]int)
	var dfs func(string) []int 
	dfs = func(s string) []int { res := make([]int, 0, len(s))
		if t, ok := cache[s]; ok {
			return t
		}

		for i := range s {
			if s[i] == '+' || s[i] == '-' || s[i] == '*' {
				for _, left := range dfs(s[:i]) {
					for _, right := range dfs(s[i+1:]) {
						res = append(res, operate(left, right, s[i]))
					}
				}
			}
		}
		if len(res) == 0 {
		   temp , _ := strconv.Atoi(s)
		   res = append(res, temp)
	    }

	    cache[s] = res
		return res
	}
	return dfs(input)
}

func operate(a, b int, opt byte) int {
	switch opt {
	case '+':
		return a + b
	case '-':
		return a - b
	default:
		return a * b
	}
}

func main() {
	fmt.Println(diffWaysToCompute("2-2-1"))
	fmt.Println(diffWaysToCompute("4-2+1"))
}
