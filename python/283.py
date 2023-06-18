from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        head, offset = 0, 0
        while head + offset < len(nums):
            while nums[head+offset] == 0:
                offset += 1
                if head + offset == len(nums):
                    break
            if head + offset < len(nums):
                nums[head] = nums[head+offset]
                head += 1
            else:
                break
        for i in range(head, len(nums)):
            nums[i] = 0
