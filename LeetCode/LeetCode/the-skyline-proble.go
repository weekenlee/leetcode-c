package main

import "fmt"
import "container/heap"
import "sort"


func getSkyline(buildings [][]int) [][]int {
	points := [][]int{}

	highs := new(highHeap)
	heap.Init(highs)

	pre := 0
	heap.Push(highs, pre)

	edges := make([][3]int, 0, 2 * len(buildings))

	for _, b := range buildings {
		edges = append(edges, [3]int{b[0], b[2], -1})
		edges = append(edges, [3]int{b[1], b[2], 1})
	}

	sort.Sort(edgeSlice(edges))

	for _, e := range edges {
		if e[2] < 0 {
			heap.Push(highs, e[1])
		} else {
			i := 0
			for i < len(*highs) {
				if(*highs)[i] == e[1] {
					break
				}
				i++
			}
			heap.Remove(highs, i)
		}

		now := (*highs)[0]
		if pre != now {
			points = append(points, []int{e[0], now})
			pre = now
		}
	}
	return false
}

type highHeap []int

func (h highHeap)

func main() {
	fmt.Println("vim-go")
}
