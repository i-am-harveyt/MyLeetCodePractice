package main


// Definition for a Node.
type Node struct {
    Val int
    Children []*Node
}


func levelOrder(root *Node) [][]int {
    var ret [][]int = make([][]int, 0)
    if (root == nil) {
        return ret
    }
    var q []*Node = make([]*Node, 0)
    q = append(q, root)
    for len(q) > 0 {
        var size int = len(q)
        ret = append(ret, make([]int, 0))
        for size > 0 {
            var cur *Node = q[0]
            ret[len(ret)-1] = append(ret[len(ret)-1], cur.Val)
            q = q[1:]
            size--
            for _, c := range cur.Children {
                q = append(q, c)
            }
        }
    }
    return ret
}
