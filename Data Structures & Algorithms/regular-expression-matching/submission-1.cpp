class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;  // empty string matches empty pattern

        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // check p[j-1], s[i-1], etc.
                if(p[j-1] == s[i-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j - 2];
                        // Case 2: one or more occurrences
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                }else{
                    dp[i][j] = 0;
                }

            }
        }
        return dp[m][n];
    }
};
