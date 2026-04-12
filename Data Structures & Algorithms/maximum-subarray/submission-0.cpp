class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int res = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            curr += nums[i];
            curr = max(nums[i], curr);
            res = max(res, curr);
        }
        return res;
    }
};