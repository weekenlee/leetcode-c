package main

import "fmt"

func rotate(m [][]int) {
	n := len(m)
	for i:=0; i < n/2; i++ {
		for j := i; j < n - i - 1; j++ {
			temp := m[i][j]
			m[i][j] = m[n-j-1][i]
			m[n-j-1][i] = m[n-i-1][n-j-1]
			m[n-i-1][n-j-1] = m[j][n-i-1]
			m[j][n-i-1] = temp
		}
	}
}

func main() {
	m := [][]int {{1,2,3},{4,5,6},{7,8,9}}
	fmt.Println(m)
	rotate(m)
	fmt.Println(m)
}
