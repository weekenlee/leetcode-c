package main

import "fmt"

func setZeroes(m [][]int) [][]int{
	rows := make([]bool, len(m))
	cols := make([]bool, len(m[0]))

	for i := range m {
		for j := range m[i] {
			if m[i][j] == 0 {
				rows[i] = true
				rows[j] = true
			}
		}
	}

	for i:= range rows {
		if rows[i] {
			for j := range m[i] {
				m[i][j] = 0
			}
		}
	}

	for i := range cols {
		if cols[i] {
			for j := range m {
				m[j][i] = 0
			}
		}
	}

	return m
}

func main() {
	m := [][]int{{0,0,}, {1, 1,}}
	fmt.Println(setZeroes(m))
}
