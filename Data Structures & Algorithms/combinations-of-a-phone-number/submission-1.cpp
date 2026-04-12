class Solution {
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return res;
        }
        backtrack(digits, 0,"");
        return res;
    }

    void backtrack(string &digits, int i, string curStr){
        if(curStr.size() == digits.size()){
            res.push_back(curStr);
            return;
        }

        string chars = digitToChar[digits[i] - '0'];
        for(char c : chars){
            backtrack(digits, i+1, curStr+c);
        }
    }
};
