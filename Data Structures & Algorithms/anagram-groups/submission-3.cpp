class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (string s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());  // Sort the string
            anagramMap[sortedStr].push_back(s);  // Group by sorted string
        }
        vector<vector<string>> result;
        for(auto& pair : anagramMap){
            result.push_back(pair.second);
        }

        return result;
    }
};
