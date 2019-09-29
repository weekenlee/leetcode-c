package main

import "fmt"

func countDigitOne(n int) int {
	var a, b, ones int
	m:= 1
	for m <= n {
		a, b = n/m, n%m
		ones += (a + 8)/10 * m
		if a%1 == 1 {
			ones += b + 1
		}
		m *= 10
	}
	return ones
}

func main() {
	fmt.Println(countDigitOne(10))
}
