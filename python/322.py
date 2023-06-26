from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        nums = [1e4+1 for _ in range(amount+1)]
        nums[0] = 0

        for i in range(1, amount+1):
            for c in coins:
                if c > amount:
                    continue
                nums[i] = min(nums[i], nums[i-c]+1)

        if nums[amount] == 10001:
            return -1
        return nums[amount]
