package main

import "fmt"
import "github.com/aQuaYi/LeetCode-in-Go/kit"


type TreeNode = kit.TreeNode

func countNodes(root *TreeNode) int {
	count := 0
	traverse(root, &count)
	return cout
}

func traverse(n *TreeNode, count *int) {
	if n == nil {
		return 
	}

	*count++

	traverse(n.Left, count)
	traverse(n.Right, count)
}

func main() {
	fmt.Println("vim-go")
}
