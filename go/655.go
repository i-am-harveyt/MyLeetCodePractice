package main

import (
	"math"
	"strconv"
)

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// get max height to build ret array
func geth(t *TreeNode, maxh *int, h int) {
	if t == nil {
		return
	}
	if *maxh < h { // update
		*maxh = h
	}
	geth(t.Left, maxh, h+1)
	geth(t.Right, maxh, h+1)
}

// build the tree, fill num in array, binary-search-like method
func build(ret *[][]string, t *TreeNode, d, l, r int) {
	if t == nil || l > r {
		return
	}
	var mid = l + (r-l)/2
	(*ret)[d][mid] = strconv.Itoa(t.Val)
	build(ret, t.Left, d+1, l, mid-1)
	build(ret, t.Right, d+1, mid+1, r)
}

func printTree(root *TreeNode) [][]string {
	var ret [][]string = make([][]string, 0)
	var maxh int = 0
	geth(root, &maxh, 0)
	for i := 0; i <= maxh; i++ { // build answer array
		ret = append(ret, make([]string, int(math.Exp2(float64(maxh)+1)-1)))
	}
	build(&ret, root, 0, 0, len(ret[0])-1)
	return ret
}
