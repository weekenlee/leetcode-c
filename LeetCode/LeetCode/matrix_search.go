package main

import "fmt"

func searchMatrix(mat [][]int, target int) bool {
	m := len(mat)
	if m == 0 {
		return false
	}

	n := len(mat[0])
	if n == 0 {
		return false
	}

	if target < mat[0][0] || target > mat[m-1][n-1]  {
		return false
	}

	r:=0
	for r < m && mat[r][0] <= target {
		r++
	}
	r--

	i, j :=0, n-1
	for i <= j {
		med := (i + j)/2
		switch {
		case mat[r][med] < target:
			i = med + 1
		case target < mat[r][med]:
			j = med -1
		default:
			return true
		}
	}
	return mat[r][j] == target
}

func main() {
	arr := [][]int {
		[]int{
			1,2,3,4,
		},
		[]int{
			5,6,7,8,
		},
		[]int{
			9,10,11,12,
		},
	}
	fmt.Println( searchMatrix(arr, 8))
	fmt.Println( searchMatrix(arr, 13))
}
