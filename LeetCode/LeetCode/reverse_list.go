package main

import "fmt"

type ListNode struct {
	Val int
	Next *ListNode
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	if m == n {
		return head
	}
	headPre := &ListNode{}
	headPre.Next = head
	m++
	n++

	mPre, mNode, nNext := split(headPre, m ,n)
	h, e := reverse(mNode)
	mPre.Next = h
	e.Next = nNext
	return headPre.Next

}

func split(head *ListNode, m,n int) (mPre, mNode, nNext *ListNode) {
	i := 1
	for head != nil {
		if i == m -1 {
			mPre = head
			mNode = head.Next
		}

		if i == n {
			nNext = head.Next
			head.Next = nil
			break
		}

		head = head.Next
		i++
	}

	return
}

func reverse(head *ListNode)(h, e *ListNode) {
	if head == nil || head.Next == nil {
		return head, head
	}

	var end *ListNode

	h, end = reverse(head.Next)
	end.Next = head
	e = head
	return
}

func main() {
	head := &ListNode{
		1,
		&ListNode{
			2,
			&ListNode{
				3, 
				&ListNode{
					4,
					&ListNode{
						5,
						nil,
					},
				},
			},
		},
	}
	reverseBetween(head, 2, 4)
	for item:=head; item!=nil; {
		fmt.Println(item.Val)
		item = item.Next
	}
}
