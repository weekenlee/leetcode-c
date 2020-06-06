package main

import "fmt"

func addDigits(n int) int {
	return (n-1)%9 + 1
}

func main() {
	fmt.Println(addDigits(12))
}
