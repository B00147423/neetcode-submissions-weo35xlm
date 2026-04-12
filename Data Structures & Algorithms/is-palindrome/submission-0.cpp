class Solution {
public:
    bool isPalindrome(string s) {
        string myString="";

        for(char c : s){
            if (isalnum(c)){
                myString+= tolower(c);
            }
        }
        return myString == string(myString.rbegin(), myString.rend());
    }
};
