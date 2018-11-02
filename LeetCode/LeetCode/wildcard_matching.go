package main

import "fmt"

func isMatch(s string , p string) bool {
	sSize, pSize := len(s), len(p)

	dp := make([][]bool, sSize + 1)
	for i:= range dp {
		dp[i] = make([]bool, pSize + 1)
	}

	dp[0][0] = true

	for j:=1; j < pSize; j++ {
		if p[j-1] ==  '*' {
			dp[0][j] = dp[0][j-1]
		}
	}

	for i := 1; i < sSize; i++ {
		for j := 1; j < pSize; j ++ {
			if p[j-1] != '*' {
				dp[i][j] = dp[i-1][j-1] &&
							(p[j-1] == s[i-1] || p[j-1] == '?')
			} else {
				dp[i][j] = dp[i-1][j] || dp[i][j-1]
			}
		}
	}
	return dp[sSize][pSize]
}

func main() {
	fmt.Println(isMatch("aa","a"))
	fmt.Println(isMatch("aa","*"))
	fmt.Println(isMatch("cb","?a"))
	fmt.Println(isMatch("abcde","a*b"))
}
