from typing import List


class Solution:
    def dfs(self, graph, cur, left, ls, rs):
        if left and cur in rs:
            return False
        if not left and cur in ls:
            return False
        if left and cur in ls:
            return True
        elif not left and cur in rs:
            return True
        if left:
            ls.add(cur)
        else:
            rs.add(cur)
        for i in graph[cur]:
            if not self.dfs(graph, i, not left, ls, rs):
                return False
        return True

    def isBipartite(self, graph: List[List[int]]) -> bool:
        ls, rs = set(), set()
        for i in range(len(graph)):
            if i not in ls and i not in rs:
                if not self.dfs(graph, i, True, ls, rs):
                    return False
        return True
