class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        

        seen = [False] * 128

        left = 0
        right = len(s)-1
        res = 0
        for right in range(len(s)):
            idx = ord(s[right])

            while seen[idx]:
                seen[ord(s[left])] = False
                left += 1
            seen[idx] = True
            res = max(res, right - left+1)
        return res