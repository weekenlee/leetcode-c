package main

import "fmt"

func searchMatrix(matrix [][]int, target int) bool {
	m := len(matrix)
	if m == 0 {
		return false
	}

	n := len(matrix[0])
	if n == 0 {
		return false
	}

	i, j := m-1, 0
	for 0 <= i && j < n {
		if matrix[i][j] == target {
			return true
		}

		if matrix[i][j] < target {
			j++
		}else {
			i--
		}
	}
	return false
}


func main() {
	var m = [][]int{
		[]int{1, 4, 7, 11, 15},
		[]int{2, 5, 8, 12, 19},
		[]int{3, 6, 9, 16, 22},
		[]int{10, 13, 14, 17, 24},
		[]int{18, 21, 23, 26, 30},
    }

	fmt.Println(searchMatrix(m, 6))
}
