class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = coins.size() - 1; i >= 0; i--) {
            for (int a = 1; a <= amount; a++) {
                if (coins[i] <= a) {
                    dp[a] = dp[a] + dp[a - coins[i]];
                } else {
                    dp[a] = dp[a]; // no change, just skip this coin
                }
            }
        }
        return dp[amount];
    }
};