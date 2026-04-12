class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = 1;
        int res = 0;
        while(r < nums.size()){
            if(nums[l] == nums[r]){
                res = nums[l];
                break;
            }else{
                r++;
                if(r == nums.size()){
                    l++;
                    r= l+1;
                }
            }
        }
        return res;
    }
};
