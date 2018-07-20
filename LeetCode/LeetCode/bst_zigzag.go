package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func zigzagLevelOrder(node *TreeNode) [][]int {
	res := [][] int {}

	var dfs fun(*TreeNode , int)
	dfs = func(root *TreeNode, level int) {
		if root == nil	{
			return 
		}

		if level >= len(res) {
			res = append(res, []int{})
		}

		if level % 2 == 0 {
			res[level] = append(res[level], root.Val)
		}else {
			temp := make([]int, len(res[level]) + 1)
			temp[0] = root.Val
			copy(temp[1:], res[level])
			res[level] = temp
		}

		dfs(root.Left, level + 1)
		dfs(root.Right, level + 1)
	}

	dfs(root, 0)
}

func main() {
}
