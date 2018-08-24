package main

import "fmt"

type ListNode struct {
	Val int
	Next *ListNode
}

func mergeTwoLists(l1, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}

	var head, node *ListNode
	if l1.Val < l2.Val {
		head = l1
		node = l1
		l1 = l1.Next
	} else {
		head = l2
		node = l2
		l2 = l2.Next
	}

	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			node.Next = l1
			l1 = l1.Next
		} else {
			node.Next = l2
			l2 = l2.Next
		}

		node = node.Next
	}

	if l1 != nil {
		node.Next = l1
	}

	if l2 != nil {
		node.Next = l2
	}

	return head
}

func main() {
	l1 := ListNode{1, &ListNode{3, nil}}
	l2 := ListNode{2, &ListNode{4, nil}}
	l3 := mergeTwoLists(&l1,&l2)
	for l3 != nil {
		fmt.Println(l3.Val)
		l3 = l3.Next
	}
}
