class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> mp;
        for(int i =- 0; i < s.length(); i++){
            if(mp.find(s[i]) != mp.end()){
                l = max(mp[s[i]]+ 1, l);
            }
            mp[s[i]] = i;
            r =max(r, i -l+1);
        }
        return r;
    }
};
