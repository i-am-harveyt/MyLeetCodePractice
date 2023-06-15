/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxLevelSum(root *TreeNode) int {
	queue := make([]*TreeNode, 0)
	queue = append(queue, root)
	ret, max := 0, -(2 << 31)

	for level := 1; len(queue) > 0; level++ {
		sum := 0
		for size := len(queue); size > 0; size-- {
			head := queue[0]
			queue = queue[1:]

			sum += head.Val

			if head.Left != nil {
				queue = append(queue, head.Left)
			}
			if head.Right != nil {
				queue = append(queue, head.Right)
			}
		}
		if sum > max {
			max, ret = sum, level
		}
	}

	return ret
}
