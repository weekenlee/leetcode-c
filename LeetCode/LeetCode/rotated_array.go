package main

import "fmt"

func search(nums []int, target int) int {
	rotated := indexOfMin(nums) 
	size := len(nums)
	left, right := 0, size -1

	for left <= right {
		mid := (left + right) /2
	}
}

func main() {
	fmt.Println("vim-go")
}
