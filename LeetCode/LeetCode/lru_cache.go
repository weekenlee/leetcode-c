package main

import "fmt"


//双向链表节点
type doublyLinkedNode struct {
	prev, next *doublyLinkedNode
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

// Put 放入数据
func (c *LRUCache ) Put(key int, value int) {
	node, ok := c.nodes[key]

	if ok {
		node.val = value
		c.moveToFirst(node)
	}else {
		if c.len == c.cap {
			delete(c.nodes, c.last.key)
			c.removeLast()
		} else {
			c.len++
		}

		node = &doublyLinkedNode {
			key : key,
			val : value,
		}

		c.nodes[key] = node
		c.insertToFirst(node)
	}
}

func (c *LRUCache) removeLast() {
	if c.last.prev != nil {
		c.last.prev.next = nil
	} else {
		c.first = nil
	}

	c.last = c.last.prev
}

func (c *LRUCache) moveToFirst(node *doublyLinkedNode) {
	switch node {
	case c.first:
		return
	case c.last:
		c.removeLast()
	default:
		node.prev.next = node.next
		node.next.prev = node.prev
	}

	c.insertToFirst(node)
}


func (c *LRUCache) insertToFirst(node *doublyLinkedNode) {
	if c.last == nil {
		c.last = node
	}else {
		node.next = c.first
		c.first.prev = node
	}

	c.first = node
}

func main() {
	cache := Constructor(3)
	cache.Put(0,0)
	cache.Put(1,1)
	cache.Put(2,2)

	fmt.Println(cache.Get(0))
	fmt.Println(cache.Get(1))
	fmt.Println(cache.Get(2))
}
