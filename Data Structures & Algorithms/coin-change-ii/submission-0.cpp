class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1));

        for (int i = 1; i <= amount; ++i) {
            dp[i][0] = 0; 
        }

        for (int j = 0; j <= coins.size(); ++j) {
            dp[0][j] = 1;
        }


        for (int j = 1; j <= coins.size(); ++j) {        
            for (int i = 1; i <= amount; ++i) {          
                if (i >= coins[j - 1])                   
                    dp[i][j] = dp[i][j - 1] + dp[i - coins[j - 1]][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[amount][coins.size()];
            
    }
};
