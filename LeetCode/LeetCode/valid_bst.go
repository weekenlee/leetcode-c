package main

import "fmt"


func isValidBST(root *TreeNode) bool {
	MIN, MAX := -1<<63, 1<<63-1
	return recur(MIN, MAX, root)
}

func recur(min, max int, root *TreeNode) bool {
	if root == nil {
		return true
	}

	return min < root.Val && root.Val < max && 
		recur(min, root.Val, root.Left) &&
		revur(root.Val, max, root.Right)
}

func main() {
	fmt.Println("vim-go")
}
