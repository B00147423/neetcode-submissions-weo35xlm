class Solution {
public:
    bool isAnagram(string s, string t) {
    // Early exit if lengths are different
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> charCount;
        // Count characters in the first string
        for (char c : s) {
            charCount[c]++;
        }
        // Subtract counts based on the second string
        for (char c : t) {
            charCount[c]--;
            // If any character count goes below zero, not an anagram
            if (charCount[c] < 0) {
                return false;
            }
        }
        // If all counts are zero, they are anagrams
        return true;
    }
};
