package main

import "fmt"

func minWindow(s string ,  t string) string {
	have := [128]int{}
	need := [128]int{}

	for i := range t {
		need[t[i]]++
	}

	size, total := len(s), len(t)

	min := size + 1
	res := ""

	for i, j , count := 0, 0, 0; j < size; j++ {
		if have[s[j]] < need[s[j]] {
			count++
		}
		have[s[j]]++

		for i < j && have[s[i]] > need[s[i]] {
			have[s[i]]--
			i++
		}

		width := j - i + 1
		if count == total && min > width {
			min = width
			res = s[i:j+1]
		}
	}
    return res
}

func main() {
	fmt.Println(minWindow("ADOBECODEBANC", "ABC"))
}
