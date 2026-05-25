class Solution {

    
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
            cout << "\nprefix[i] = " << prefix[i];
        }

        int left = 0;
        int ans = INT_MAX;

        for (int right = 1; right <= n; right++) {

            int need = prefix[right] - target;

            while (left < right && prefix[left] <= need) {

                ans = min(ans, right - left);

                left++;
            }
        }

        if (ans == INT_MAX) {
            return 0;
        } else {
            return ans;
        }
    }
};
/*

so base case;
base case:
    minimumLengthSubArraySum < target 
        return 0

    minimumLengthSubArraySum  - vector array

    we push each element and sum 

    e can use queu?





*/