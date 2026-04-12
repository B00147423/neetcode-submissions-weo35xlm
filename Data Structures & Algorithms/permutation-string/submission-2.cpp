class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1dict;
        unordered_map<char, int> s2dict;

        if (s1.length() > s2.length()){
            return false;
        }

        for(int i = 0; i < s1.length(); i++){
            s1dict[s1[i]]++;
            s2dict[s2[i]]++;
        }
        if (s1dict == s2dict) {
            return true;
        }
        int l = 0;
        for(int right = s1.size(); right < s2.size(); right++){
            s2dict[s2[right]]++;
            s2dict[s2[l]]--;
            if(s2dict[s2[l]] == 0){
                s2dict.erase(s2[l]);
            }
            l++;
            if (s1dict == s2dict) {
                return true;
            }
        }
        return false;
    }
};
