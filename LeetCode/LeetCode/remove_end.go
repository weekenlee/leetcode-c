package main

import "fmt"

type ListNode struct {
	Val int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummy := &ListNode{-1,head}
	slow, fast := dummy, dummy
	for i:=0; i<n; i++ {
		fast=fast.Next
	}

	for fast.Next != nil {
		fast = fast.Next
		slow = slow.Next
	}
	
	slow.Next = slow.Next.Next

	return dummy.Next
}


func removeNthFromEnd2(head *ListNode, n int) *ListNode {
	d, headIsNthFromEnd := getDaddy(head, n)

	if headIsNthFromEnd {
		return head.Next
	}

	d.Next = d.Next.Next

	return head
}

func getDaddy(head *ListNode , n int) (daddy *ListNode, headIsNthFromEnd bool) {
	daddy = head

	for head != nil {
		if n < 0 {
			daddy = daddy.Next
		}
		n--
		head = head.Next
	}

	headIsNthFromEnd = n == 0
	return
}

func main() {
	head := &ListNode {
		1,
		&ListNode {
			2,
			&ListNode {
				3, 
				&ListNode{
					4,
					&ListNode {
						5,
						nil,
					},
				},
			},
		},
	}

	result := removeNthFromEnd(head, 3)
	for result.Next != nil {
		fmt.Println(result.Val)
		result=result.Next
	}
}
