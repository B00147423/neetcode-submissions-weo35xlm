class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0 , right = numbers.size()-1;

        while(left < right){
            int res = numbers[left] + numbers[right];
            if(res < target){
                left++;
            }else if(res > target){
                right--;
            }else{
                return{left+1, right+1};
            }
        }
        return {};
    }
};
