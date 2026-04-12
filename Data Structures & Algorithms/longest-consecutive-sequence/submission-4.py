class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        numsSet = set(nums) 
        longest = 0
        for num in numsSet:
            #check if it's start of a  sequence
            if (num-1) not in numsSet:
                length = 0
                while (num + length) in numsSet:
                    length +=1
                # Update the longest streak
                longest = max(length, longest)
        
        return longest
