package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}

	if root.Left == nil && root.Right == nil {
		return []int{root.Val}
	}

	res := inorderTraversal(root.Left)
	res = append(res, root.Val)
	res = append(res, inorderTraversal(root.Right)...)

	return res
}

func main() {
	root := &TreeNode{
		1,
		nil,
		&TreeNode{
			2,
			&TreeNode{
				3,
				nil,
				nil,
			},
			nil,
		},
	}

	fmt.Println(inorderTraversal(root))
}
