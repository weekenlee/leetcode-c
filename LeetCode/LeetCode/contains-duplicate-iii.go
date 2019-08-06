package main

import "fmt"

func containsNearbyAlmostDuplicate(nums []int, k, t int) bool{
	size := len(nums)
	if k == 0 || t < 0 || size <= 1 {
		return false
	}

	t++

	nMap := make(map[int]int, size)
	var ni, m int
	for i := 0; i < size; i++ {
		ni = nums[i]
		m = ni / t
		if ni < 0 {
			m--
		}
		if _, ok := nMap[m]; ok {
			return true
		} else if n , ok := nMap[m-1]; ok && abs(ni, n) < t {
			return true
		} else if n, ok := nMap[m+1]; ok && abs(ni, n) < t {
			return true
		}

		nMap[m] = ni
		if i >= k {
			delete(nMap, nums[i - k] / t)
		}
	}
	return false
}

func abs( a, b int ) int {
	if a > b {
		return a - b
	}
	return b - a
}


func main() {
	fmt.Println("vim-go")
}
