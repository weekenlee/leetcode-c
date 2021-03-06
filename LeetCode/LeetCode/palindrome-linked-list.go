package main

import ("github.com/aQuaYi/leetCode-in-Go/kit")

type ListNode = kit.ListNode

func isPalindrome(head *ListNode) bool {
	nums := make([]int, 0, 64)
	for head != nil {
		nums = append(nums,head.Val)
		head = head.Next
	}

	l, r := 0, len(nums)-1
	for l < r {
		if nums[l] != nums[r] {
			return false
		}
		l++
		r--
	}
	return true
}

func main() {
	fmt.Println("vim-go")
}
