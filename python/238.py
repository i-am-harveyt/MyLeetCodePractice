from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size = len(nums)
        ret: List[int] = [1 for _ in range(size)]

        cur = 1
        # l -> r
        for i in range(size):
            ret[i] *= cur
            cur *= nums[i]
        # r -> l
        cur = 1
        for i in range(size-1, -1, -1):
            ret[i] *= cur
            cur *= nums[i]

        return ret
