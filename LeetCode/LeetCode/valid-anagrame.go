package main

import "fmt"

func isAnagram(s string , t string) bool {
	if len(s) != len(t) {
		return false
	}

	sr := []rune(s)
	tr := []rune(t)

	rec := make(map[rune]int , len(s))
	for i := range sr {
		rec[sr[i]]++
		rec[tr[i]]--
	}

	for _, n := range rec {
		if n != 0 {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(isAnagram("hi", "hi"))
	fmt.Println(isAnagram("ai", "hi"))
}
