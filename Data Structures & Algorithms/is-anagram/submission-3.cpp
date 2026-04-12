class Solution {
public:
    bool isAnagram(string s, string t) {
    
        if(s.size() != t.size()) return false;
        unordered_map<char, int> m_freq;

        for (char c : s) {
            m_freq[c]++; 

        }

        for(char c : t){
            m_freq[c]--;
             if (m_freq[c] < 0) return false;  
        }


        
    return true;    
    }
};
