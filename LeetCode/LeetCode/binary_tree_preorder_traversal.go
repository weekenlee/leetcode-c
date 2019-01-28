package main

<<<<<<< HEAD
import (
    "fmt"
	"github.com/aQuaYi/LeetCode-in-Go/kit"
)

type TreeNode = kit.TreeNode

func preorderTraversal(root *TreeNode) []int {
=======
import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func preorderTraversal(root *TreeNode) {
>>>>>>> 035e53e55b533602d2cd2e9684239982bc37b853
	var rightStack []*TreeNode
	var res []int

	for cur := root; cur != nil; {
		res = append(res, cur.Val)

		if cur.Left != nil {
			if cur.Right != nil {
				rightStack = append(rightStack, cur.Right)
			}
			cur = cur.Left
		}else {
			if cur.Right != nil {
				cur = cur.Right
			}else {
				if len(rightStack) == 0 {
					break
				}

				cur = rightStack[len(rightStack) - 1]
				rightStack = rightStack[:len(rightStack) - 1]
			}
		}
<<<<<<< HEAD

=======
>>>>>>> 035e53e55b533602d2cd2e9684239982bc37b853
	}
	return res
}

<<<<<<< HEAD

=======
>>>>>>> 035e53e55b533602d2cd2e9684239982bc37b853
func main() {
	fmt.Println("vim-go")
}
