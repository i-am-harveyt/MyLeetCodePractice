class Solution(object):
    def find(self, n, set):
        if set[n] < 0:
            return n
        set[n] = self.find(set[n], set)
        return set[n]

    def union(self, p, q, set):
        p1, p2 = self.find(p, set), self.find(q, set)
        if p1 == p2:
            return
        if (set[p1] <= set[p2]):
            set[p1] += set[p2]
            set[p2] = p1
        else:
            set[p2] += set[p1]
            set[p1] = p2

    def countPairs(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        ds = [-1 for _ in range(n)]
        for i in range(len(edges)):
            self.union(edges[i][0], edges[i][1], ds)
        a, b = 0, 0
        for i in range(n):
            if ds[i] < 0:
                a, b = a + ds[i], b + ds[i]**2
        return (a**2 - b)//2
