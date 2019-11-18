package main

import "github.com/aQuaYi/LeetCode-in-Go/kit"


type ListNode = kit.ListNode

func deleteNode(node *ListNode) {
	node.Val = node.Next.Val
	node.Next = node.Next.Next
}

func main() {
	fmt.Println("vim-go")
}
