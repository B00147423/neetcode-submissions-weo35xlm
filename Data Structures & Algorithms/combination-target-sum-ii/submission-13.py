class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def backtrack(start, subset, remaining):
            if remaining == 0:
                res.append(subset[:])
                return
            
            for i in range(start, len(candidates)):
            
                # skip duplicates
                if i > start and candidates[i] == candidates[i-1]:
                    continue

                if candidates[i] > remaining:
                    break    

                subset.append(candidates[i])
                backtrack(i + 1, subset, remaining - candidates[i])
                subset.pop()
    
        backtrack(0, [], target)
        return res


