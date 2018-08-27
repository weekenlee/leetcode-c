package main

import "fmt"

func minPathSum(grid [][]int ) int {
	m := len(grid)
	n := len(grid[0])

	for i := 0; i < m; i++ {
		for j := 0;  j < n; j++ {
			fmt.Printf("%v ", grid[i][j])
		}
		fmt.Printf("\n")
	}

	dp := make([][]int, m)

	for i:= range dp {
		dp[i] = make([]int, n)
	}

	dp[0][0] = grid[0][0]
	sum := dp[0][0]
	for i := 1; i < m ; i++ {
		sum += grid[i][0]
		dp[i][0] = sum 
	}

	sum = dp[0][0]
	for j := 1; j < n; j++ {
		sum += grid[0][j]
		dp[0][j] = sum 
	}

	for i := 1; i < m; i++ {
		for j := 1;  j < n; j++ {
			dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
		}
	}

	fmt.Println(dp)
	return dp[m-1][n-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return a
}

func main() {
    //a.exe 131 151 421
	grid := [][]int{[]int{1,3,1}, []int{1,5,1}, []int{4,2,1}}
	fmt.Println(minPathSum(grid))
}
