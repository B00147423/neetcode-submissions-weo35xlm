class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, res = 0;

        for(int right = 0; right < s.size(); right++){
            if(mp.find(s[right]) != mp.end()){
                l = max(mp[s[right]] + 1, l);
            }
            mp[s[right]] = right;
            res = max(res, right-l +1);
        }
        return res;
    }
};
