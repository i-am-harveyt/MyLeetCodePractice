package main

import (
	"strconv"
	"strings"
)

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func tree2str(root *TreeNode) string {
	var ret []string = make([]string, 0)
	var helper func(t *TreeNode)
	helper = func(t *TreeNode) {
		if t == nil {
			return
		}
		ret = append(ret, strconv.Itoa(t.Val))
		if t.Left != t.Right {
			ret = append(ret, "(")
			helper(t.Left)
			ret = append(ret, ")")
			if t.Right != nil {
				ret = append(ret, "(")
				helper(t.Right)
				ret = append(ret, ")")
			}
		}
	}
	helper(root)
	return strings.Join(ret, "")
}
