from typing import List


class Solution:
    def __init__(self):
        self.__memo = dict()
        self.__mod = 1e9+7

    def __helper(self,
                 grid: List[List[int]],
                 r: int, c: int,
                 prev: int = 0) -> int:
        key = (r, c)
        if r < 0 or c < 0 or r == len(grid) or c == len(grid[0]):
            return 0
        elif grid[r][c] <= prev:
            return 0
        elif key in self.__memo:
            return self.__memo[key]

        self.__memo[key] = \
            ((((1 +
             self.__helper(grid, r, c+1, grid[r][c])) % self.__mod +
             self.__helper(grid, r, c-1, grid[r][c])) % self.__mod +
             self.__helper(grid, r+1, c, grid[r][c])) % self.__mod +
             self.__helper(grid, r-1, c, grid[r][c])) % self.__mod

        return self.__memo[key]

    def countPaths(self, grid: List[List[int]]) -> int:
        sum = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                sum = (sum + self.__helper(grid, i, j)) % self.__mod
        return int(sum)
