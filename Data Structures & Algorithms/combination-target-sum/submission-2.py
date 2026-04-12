class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        '''
            the brute force =

            loop over nm compare the result of numbers thjat made the target


            my approach:

            we halready know the target, we take first nums[i]

            nums = [2,5,6,9] 

            so target =  9 - 2*2 = 5

            then the check if target is in trhe output and append it to result
        '''
        res = []

        def dfs(i, cur, total):
            if total == target:
                res.append(cur.copy())
                return
            if i >= len(nums) or total > target:
                return
            
            cur.append(nums[i])
            dfs(i, cur, total + nums[i])
            cur.pop()
            dfs(i+1, cur, total)
        dfs(0, [], 0)
        return res