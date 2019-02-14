package main

import "fmt"


//双向链表节点
type doublyLinkNode struct {
	prev, next *doublyLinkNode
	key, val int
}

//LRUCache 利用双向链表 + hashtable 实现
type LRUCache struct {
	len , cap int
	first , last *doublyLinkedNode
	nodes map[int] *doublyLinkedNode
}

//Constructor 创建容量为capacity的cache
func Constructor(capacity int) LRUCache {
	return LRUCache {
		cap : capacity,
		nodes: make(map[int]*doublyLinkedNode, capacity),
	}
}

// Get 获取数据
func (c *LRUCache) Get(key int) int {
	if node, ok := c.nodes[key]; ok {
		c.moveToFirst(node)
		return node.val
	}

	return -1
}



func main() {
	fmt.Println("vim-go")
}
