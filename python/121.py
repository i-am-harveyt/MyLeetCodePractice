from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [0 for _ in range(len(prices))]
        min_idx = 0

        for i in range(len(prices)):
            if prices[i] < prices[min_idx]:
                min_idx = i
            dp[i] = min_idx

        max = 0
        for i in range(len(prices)):
            if prices[i] - prices[dp[i]] > max:
                max = prices[i] - prices[dp[i]]

        return max
