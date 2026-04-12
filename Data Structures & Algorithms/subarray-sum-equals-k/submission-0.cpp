class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0, curSum = 0;
        unordered_map<int, int> prefixSums;


        /*
        
nums=[2,-1,1,2]
k=2
        
curSum : 2, difference : 0, res : 1

curSum : 1, difference : -1, res : 1

curSum : 2, difference : 0, res : 2

curSum : 4, difference : 2, res : 4



        */
        prefixSums[0] = 1;
        for(int  num : nums){
            curSum += num;

            int difference = curSum -k; 
            
            result += prefixSums[difference];

            prefixSums[curSum]++;
        }
         return result;
    }
   
};