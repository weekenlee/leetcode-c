package main

import "fmt"

func removeElement(nums []int, val int) int {
	i , j := 0, len(nums)-1
	for{
		for i<len(nums) && nums[i] != val {
			i++
		}

		for j >= 0 && nums[j] == val {
			j--
		}

		if i >= j {
			break
		}

		nums[i], nums[j] = nums[j], nums[i]
	}
	return i
} 

func main() {
	v := []int{1,2,3,4}
	fmt.Println(removeElement(v, 3))
	fmt.Println(v)
}
