class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size()-1;

        int jumpCount = 0;
        int currJump = 0;
        int farthest = 0;

        for(int i = 0; i < n; i++)
        {
            farthest = max(farthest, i + nums[i]);
            if(i == currJump){
                jumpCount++;
                currJump = farthest;
            }
        }
        return jumpCount;
    }
};
