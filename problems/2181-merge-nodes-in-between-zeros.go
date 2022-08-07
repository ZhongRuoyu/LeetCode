// Solved 2022-08-07
// Runtime: 376 ms (83.33%)
// Memory Usage: 12.8 MB (93.33%)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeNodes(head *ListNode) *ListNode {
	var newHead *ListNode
	var newTail *ListNode
	sum := 0
	node := head.Next
	for node != nil {
		if node.Val == 0 {
			newNode := &ListNode{
				Val:  sum,
				Next: nil,
			}
			if newHead == nil {
				newHead = newNode
			} else {
				newTail.Next = newNode
			}
			newTail = newNode
			sum = 0
		} else {
			sum += node.Val
		}
		node = node.Next
	}
	return newHead
}
