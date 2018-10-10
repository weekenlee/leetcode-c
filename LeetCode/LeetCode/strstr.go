package main

import "fmt"

func strStr(haystack string, needle string) int {
	hlen , nlen := len(haystack), len(needle)

	for i := 0; i <= hlen-nlen; i++ {
		if haystack[i:i+nlen] == needle {
			return i
		}
	}

	return -1
}

func main() {
	fmt.Println(strStr("abcdefg", "eft"))
	fmt.Println(strStr("abcdefg", "efg"))
}
