from typing import List


class Solution:
    def canFinish(self, numCourses: int,
                  prerequisites: List[List[int]]) -> bool:
        # calculate in-degree
        in_deg = [0 for _ in range(numCourses)]
        adj_list: List[List[int]] = [[] for _ in range(numCourses)]
        for pair in prerequisites:
            adj_list[pair[1]].append(pair[0])
            in_deg[pair[0]] += 1

        queue: List[int] = []
        for i in range(numCourses):
            if in_deg[i] == 0:
                queue.append(i)

        while len(queue) != 0:
            cur = queue[0]
            queue = queue[1:]
            for n in adj_list[cur]:
                in_deg[n] -= 1
                if in_deg[n] == 0:
                    queue.append(n)

        for n in in_deg:
            if n != 0:
                return False
        return True
