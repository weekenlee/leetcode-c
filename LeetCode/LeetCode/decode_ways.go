package main

import "fmt"
import "os"

func numDecoding(s string) int {
	if len(s) == 0	{
		return 0
	}

	prev := 0
	cur := 1

	for i:=0; i<len(s); i++ {
		if s[i] == '0' {
			cur = 0
		}

		if i==0 || !(s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')) {
			prev = 0
		}

		tmp := cur
		cur += prev
		prev = tmp
	}
	return cur
}

func main() {
	fmt.Println(numDecoding(os.Args[1]))
}
