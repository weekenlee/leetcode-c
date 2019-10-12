package main

import "fmt"
import "github.com/aQuaYi/LeetCode-in-Go/kit"

type TreeNode = kit.TreeNode

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	return helper(root, p.Val, q.Val)
}

func helper(root *TreeNode, p, q int) *TreeNOde {
	r := root.Val
	if p < r && q < r {
		return helper(root.Left, p, q)
	}else if r < p && r < q {
		return helper(root.Right, p, q)
	}
	return root
}

func main() {
	fmt.Println("vim-go")
}
