package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	res := [][]int{}
	var dfs func(*TreeNode, int)

	dfs = func(root *TreeNode , level int) {
		if root == nil {
			return
		}

		if level >= len(res) {
			res = append(res, []int{})
		}

		res[level] = append(res[level], root.Val)

		dfs(root.Left, level + 1)
		dfs(root.Right, level + 1)
	}
	dfs(root, 0)
	return res
}

func main() {
	root := &TreeNode{
		3,
		&TreeNode{
			9,
			&TreeNode{
				15,
				nil,
				nil,
			},
			&TreeNode{
				7,
				nil,
				nil,
			},
		},
		&TreeNode{
			20,
			nil,
			nil,
		},
	}

	fmt.Println(*root)

	res := levelOrder(root)

	fmt.Println(res)

	for _, subarr := range res {
		for _, item := range subarr {
			fmt.Printf("%v ", item)
		}
		fmt.Println()
	}
}
