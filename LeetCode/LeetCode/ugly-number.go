package main

import "fmt"

func isUgly(num int) bool {
	if num <= 0 {
		return false
	}

	if num <= 6 {
		return true
	}

	if num%2 == 0 {
		return isUgly(num/2)
	}

	if num%3 == 0 {
		return isUgly(num/3)
	}

	if num%5 == 0 {
		return isUgly(num/5)
	}

	return false
}

func main() {
	fmt.Println(isUgly(6))
	fmt.Println(isUgly(5))
	fmt.Println(isUgly(9))
}
