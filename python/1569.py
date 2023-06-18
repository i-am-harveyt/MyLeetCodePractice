from typing import List
import math


class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        modular = 10**9 + 7

        def helper(nums):
            if len(nums) <= 2:
                return 1
            left, right = [], []
            for num in nums:
                if num < nums[0]:
                    left.append(num)
                elif num > nums[0]:
                    right.append(num)

            return helper(left) * helper(right) * \
                math.comb(len(nums)-1, len(nums)-len(left)-1) %\
                modular

        return helper(nums)-1
