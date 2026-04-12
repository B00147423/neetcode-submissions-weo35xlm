class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>count;
        int res = 0;
        int l = 0;
        int maxF = 0;
        for(int r = 0; r < s.size(); r++){
            count[s[r]]++;
            maxF = max(maxF, count[s[r]]);
            // If needed replacements (window_size - maxF) exceed k, shrink window from left
            while ((r - l + 1) - maxF > k) {
                count[s[l]]--;  // Remove the leftmost character from frequency count
                l++;            // Shrink the window
            }
            res = max(res, r - l + 1);
        }
    return res;
    }
};
