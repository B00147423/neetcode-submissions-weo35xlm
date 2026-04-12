class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        res = [1] * (len(nums))

        prefix = 1

        for i in range(len(nums)):
            res[i] = prefix
            print(res[i])
            prefix *= nums[i]

        prefix = 1
        for i in range(len(nums) -1, -1, -1):
            res[i] *= prefix
            prefix *= nums[i]
        return res


        '''
        nums = [1,2,4,6]
        prefix = 1

        print(prefix)   # 1
        prefix *= 1     # -> 1

        print(prefix)   # 1
        prefix *= 2     # -> 2

        print(prefix)   # 2
        prefix *= 4     # -> 8

        print(prefix)   # 8

                
        res [1,1,2,8] 
        nums=[1,2,4,6] 
        res = 8 * 1 = 8     | 2*6 = 12   | 1 * 24 = 24      | 48 * 1 = 48 
        prefix 1 * 6= 6     | 6*4= 24    | 24 * 2 = 48 
        
        res = [48. 24, 12, 8]


        '''
