class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1dict;
        unordered_map<char, int> window;
        
        if (s2.size() < s1.size()){
            return false;
        }

        for (char c : s1){
            s1dict[c]++;
        }

       for (int i = 0; i < s1.size(); i++) {
            window[s2[i]]++;
        }

        
        if (s1dict == window) {
            return true;
        }

        int left = 0;


        for (int right = s1.size(); right < s2.size(); right++) {
            char leftChar = s2[left];
            window[leftChar]--;

            if (window[leftChar] == 0){
                window.erase(leftChar);
            }
            left++;

            char rightChar = s2[right];
            window[rightChar]++;

            if (window == s1dict){
                return true;
            }
        }

        return false;


    }
};
