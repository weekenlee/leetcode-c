package main

import "fmt"

func bigger(a , b int) int {
	if a > b {
		return a
	}
	return b
}

func smaller(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func trap(height []int) int {
	length := len(height)
	if length <= 2 {
		return 0
	}

	left, right := make([]int, length), make([]int, length) 
	left[0], right[length-1] = height[0], height[length-1]
	for i := 1; i < length; i++ {
		left[i] = bigger(left[i-1], height[i])
		right[length-1-i] = bigger(right[length-i], height[length-1-i])
	}

	water := 0
	for i:=0; i<length;i++ {
		water += smaller(left[i], right[i]) - height[i]
	}

	return water
}

func main() {
	fmt.Println(trap([]int{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }))
}
