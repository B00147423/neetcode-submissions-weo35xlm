class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(perm):
            if len(perm) == len(nums):
                res.append(perm[:])
                return

            for n in nums:
                if n in perm:
                    continue
                perm.append(n)
                backtrack(perm)
                perm.pop()

        backtrack([])
        return res