package main

import "fmt"

func d(m, n int) int {
	res := 0
	rs, ress :=	[]int{n}, []int{1}
	temp , i:= n + n , 1

	for temp <= m {
		rs = append(rs, temp)
		ress = append(ress, ress[i-1]+ress[i-1])
		temp += temp
		i++
	}

	for i:=len(rs) - 1; i>=0; i-- {
		if m >= rs[i] {
			m -= rs[i]
			res += ress[i]
		}
	}
	return res
}

func main() {
	fmt.Println(d(13,3))
}
