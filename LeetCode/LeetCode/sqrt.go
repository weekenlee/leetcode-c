package main

import "fmt"

func mySqrt(x int) int {
	res := x

	for res*res > x {
		res = (res + x/res) / 2
	}

	return res
}

func main() {
	fmt.Println(mySqrt(10))
}
