class Solution(object):
    def runningSum(self, nums) -> list[int]:
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i in range(1, len(nums)):
            nums[i] += nums[i-1]
        return nums

    def foo(self) -> int:
        var = 0
        while var < 10:
            var += 1
        return var
