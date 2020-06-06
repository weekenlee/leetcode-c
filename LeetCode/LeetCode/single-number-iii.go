package main

import "fmt"

func singleNumber(nums []int) []int {
	var xor int
	for _, num := range nums {
		xor ^= num
	}

	lowest := xor & -xor

	var a, b int
	for _, num := range nums {
		if num&lowest == 0	{
			a ^= num
		} else {
			b ^= num
		}
	}

	return []int{a, b}
}

func main() {
	v := []int {1,2,3,2,3,5}
	fmt.Println(singleNumber(v))
}
