class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        memo = {len(s) : True}

        def dfs(index):

            if index in memo:
                return memo[index]

            for word in wordDict:
                if s[index : index + len(word)] == word:
                    if dfs(index + len(word)):
                        memo[index] = True
                        return True
            memo[index] = False # Store the result
            return False
        return dfs(0)
