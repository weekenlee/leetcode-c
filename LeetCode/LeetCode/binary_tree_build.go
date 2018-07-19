package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func buildTree(pre, in  []int) *TreeNode {
	if len(in) == 0	{
		return nil
	}

	res := &TreeNode{
		Val:pre[0],
	}

	if len(in) == 1 {
		return res
	}

	idx := indexOf(res.Val, in)

	res.Left = buildTree(pre[1:idx+1], in[:idx])
	res.Right = buildTree(pre[idx+1:], in[idx+1:])

	return res
}

func indexOf(val int, nums[] int) int {
	for i, v := range nums {
		if v == val {
			return i
		}
	}
	return 0
}

func main() {
	arr1 := []int{1,2,3}
	arr2 := []int{2,1,3}
 	res := 	buildTree(arr1, arr2)
	fmt.Println(res.Val, res.Left.Val, res.Right.Val)
}
