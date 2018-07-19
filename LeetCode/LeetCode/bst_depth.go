package main

import "fmt"


func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	return 1 + max(maxDepth(root.Left), maxDepth(root.right))
}

func max(a, b int )int {
	if a>b {
		return a
	}
	return b
}


func main() {
	fmt.Println("vim-go")
}
