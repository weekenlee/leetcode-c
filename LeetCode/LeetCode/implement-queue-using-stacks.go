package main

import "fmt"
import "container/list"

type MyQueue struct {
	list *list.List
}

func Constructor() MyQueue {
	return MyQueue {
		list : list.New(),
	}
}

func (q *MyQueue) Push(x int) {
	q.list.PushBack(x)
}

func (q *MyQueue) Pop() int {
	front := q.list.Front()
	res := front.Value.(int)
	q.list.Remove(front)
	return res
}

func (q *MyQueue) Peek() int {
	front := q.list.Front()
	res := front.Value.(int)
	return res
}

func (q *MyQueue) Empty() bool {
	return q.list.Len() == 0
}

func main() {
}
