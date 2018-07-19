package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	mid := len(nums)/2
	return &TreeNode{
		Val: nums[mid],
		Left: sortedArrayToBST(nums[:mid]),
		Right: sortedArrayToBST(nums[mid+1:]),
	}
}

func main() {

	nums := []int{1,2,3,4,5,6}
	re := sortedArrayToBST(nums)
	fmt.Println(re)
}
