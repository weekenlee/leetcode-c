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
	record := make(map[string]int, lenws)
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

	/*
	s[left:right] 作为一个窗口存在
	假设 word := s[right : right + lenw]
	如果 remain[word]>0, 那么移动窗口右边，同时更新移动后的s[left:right]统计信息
	remain[word]--
	right += lenw
	count++
	否则，移动窗口 左边，同时更新移动后 s[left:right] 的统计信息
	remain[s[left:left+lenw]]++
	count--
	left += lenw
	每次移动窗口 右边 后，如果 count = lenws ，那么
	说明找到了一个符合条件的解
	append(res, left)，然后
	移动窗口 左边
	*/

	reset := func() {
		if count == 0 {
			return
		}
		for k, v :=range record {
			remain[k] = v
		}
		count = 0
	}

	moveLeft := func() {
		remain[s[left:left+lenw]]++
		count--
		left += lenw
	}

	for i := 0; i < lenw; i++ {
		left, right = i, i
		reset()

		for lens-left >= lenws*lenw {
			word := s[right: right+lenw]
			remainTimes, ok := remain[word]

			switch {
			case !ok:
				left, right = right + lenw, right + lenw
				reset()
			case remainTimes == 0:
				moveLeft()
			default:
				remain[word]--
				count++
				right += lenw
				if count == lenws {
					res = append(res, left)
					moveLeft()
				}
			}
		}
	}
	return res

}

func main() {
	s := "barfoothefoobarman"
	words :=[]string{"foo","bar"}
	fmt.Println(findSubstring(s, words))
}
