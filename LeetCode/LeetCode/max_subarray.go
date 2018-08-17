package main

import (
    "fmt"
)

func maxSubArray(nums []int) int {
    l := len(nums)

    if l == 0 {
        return 0
    }

    if l == 1 {
        return 1
    }

    temp := nums[0]
    max := temp
    i := 1

    for i < l {
        if temp < 0 {
            temp = nums[i]
        } else {
            temp += nums[i]
        }

        if max < temp {
            max = temp
        }

        i++
    }

    return max
}

func main() {
    fmt.Println(maxSubArray([]int{-2,1,-3,4,-1,2,1,-5,4}))
}
