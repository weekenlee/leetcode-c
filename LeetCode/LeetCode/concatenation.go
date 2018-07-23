package main

import "fmt"

func findSubstring(s string, words []string) []int {
	lens := len(s)
	res := make([]int, 0, lens)

	lenws := len(words)
	if lens == 0 || lenws == 0 || lens < lenws*len(words[0]) {
		return res
	}

	lenw := len(words[0])

	//record记录words中每个单词出现总次数
	record := make(map[string][int], lenws)

	for _, w := range words {
		if len(w) != lenw {
			//违反长度一致的假设
			return res
		}
		record[w]++
	}

	//remain 记录words中每个单词还能出现的次数
	remain := make(map[string]int, lenws)
	//count 记录符合要求的单词连续出现次数
	count := 1
	left , right := 0, 0

}

func main() {
	fmt.Println("vim-go")
}
