class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        res = [1] * (len(nums))

        prefix = 1

        for i in range(len(nums)):
            res[i] = prefix
            
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

        
        prefix  = from idnex 1 to 3
            [1,2,4,6]
            prefix = 1  * 1 = 1
                prefix = 1 * 2 = 2
                    prefix = 2* 4 = 8
                        prefix = 8 * 6 =48


        '''
