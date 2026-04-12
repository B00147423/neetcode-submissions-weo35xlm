class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        '''
            numbers = [1,2,3,4], target = 3

            target
            difference = target - 3

            if that is in the nums array


                while(seen.count[nums[i]])


        '''
        left = 0
        seen = {}
        for i in range(len(numbers)):
            difference = target - numbers[i]

            if difference in seen:
                return [seen[difference] + 1, i + 1]
            seen[numbers[i]] = i

        return []