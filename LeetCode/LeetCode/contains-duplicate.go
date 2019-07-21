package main

import "fmt"

func containsDuplicate(nums []int) bool {
	m := make(map[int]bool, len(nums))
	for _, n := range nums {
		if m[n] {
			return true
		}

		m[n] = true
	}

	return false
}

func main() {
	v := []int{1,2,3,4,1,2}
	v1 := []int{1,2,3,4}
	fmt.Println(containsDuplicate(v))
	fmt.Println(containsDuplicate(v1))
}
