package main

import "fmt"
import "strings"

func fullJustify(words []string, maxWidth int) []string {
	res := []string{}
	temp := []string{}
	width := 0
	isLast := false

	for !isLast {
		words, temp, width, isLast = split(words, maxWidth)
		res = append(res, combine(temp, width, maxWidth, isLast))
	}

	return res
}

func split(words []string, maxWidth int) ([]string, []string, int, bool) {
	temp := make([]string, 1)
	temp[0] = words[0]
	width := len(words[0])

	i := 1

	for ; i < len(words); i++ {
		if width + len(temp) + len(words[i]) > maxWidth {
			break
		}
		temp = append(temp, words[i])
		width += len(words[i])
	}

	return words[i:], temp, width, i == len(words)
}

func combine(words []string, width, maxWidth int, isLast bool) string {
	wordCount :=len(words)
	if wordCount == 1 || isLast {
		return combineSpecial(words, maxWidth)
	}

	spaceCount := wordCount - 1
	spaces := makeSpaces(spaceCount, maxWidth - width)

	res := ""
	for i, v := range spaces {
		res += words[i] +v
	}

	if wordCount > 1 {
		res += words[wordCount -1]
	}

	return res
}

func makeSpaces(len, count int) []string {
	res := make([]string, len)
	for i:=0; i < count; i++ {
		res[i%len] += " "
	}
	return res
}

func combineSpecial(words []string, maxWidth int) string {
	res := strings.Join(words, " ")

	for len(res) < maxWidth	 {
		res += " "
	}
	return res
}

func main() {
	str := []string {"This", "is", "an", "exmaple", "of", "text", "justification."}
	for _, item := range fullJustify(str, 15) {
		fmt.Println(item)
	}
}
