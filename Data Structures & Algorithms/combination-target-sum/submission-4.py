class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        res = []
        self.backtrack(nums, 0, [], target, res)
        return res

    def backtrack(self, nums, start, subset, remaining, res):
        if remaining == 0:
            res.append(subset[:])
            return

        for i in range(start, len(nums)):
            if nums[i] > remaining:
                continue

            subset.append(nums[i])
            self.backtrack(nums, i, subset, remaining - nums[i], res)
            subset.pop()

