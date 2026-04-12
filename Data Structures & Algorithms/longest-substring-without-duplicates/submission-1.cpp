class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, char> mp;
        int l = 0;
        int res = 0;

        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                l = max(mp[s[i]]+1, l);
            }
            mp[s[i]] = i;
            res = max(res, i-l+1);
        }
        return res;
    }
};
