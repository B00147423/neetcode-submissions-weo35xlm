import sys
sys.setrecursionlimit(10**6)

class Solution:
    def dfs(self, i, j):
        if i == len(self.nums):
            return 0
        
        if self.memo[i][j+1] != -1:
            return self.memo[i][j+1]

        LIS = self.dfs(i + 1, j)

        if j == -1 or self.nums[j] < self.nums[i]:
            LIS = max(LIS, 1 + self.dfs(i + 1, i))

        self.memo[i][j+1] = LIS
        return LIS

    def lengthOfLIS(self, nums):
        self.nums = nums
        n = len(nums)
        self.memo = [[-1] * (n + 1) for _ in range(n)]
        return self.dfs(0, -1)