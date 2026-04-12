class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        memo = [[-1] * 2 for _ in range(len(prices))]

        def dfs(i, j):
            if i >= len(prices):
                return 0
            if memo[i][j] != -1:
                return memo[i][j]

            if j == 0:
                buy = dfs(i + 1, 1) - prices[i]
                skip = dfs(i + 1, 0)
                memo[i][0] = max(buy, skip)
            else:
                sell = dfs(i + 2, 0) + prices[i]
                hold = dfs(i + 1, 1)
                memo[i][1] = max(sell, hold)

            return memo[i][j]
        return dfs(0, 0)