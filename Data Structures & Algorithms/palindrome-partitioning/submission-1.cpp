class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, 0, path);
        return res;
    }

private:
    void dfs(string s, int i, vector<string>& path){
        if (i == s.size()) {
            res.push_back(path);
            return;
        }


        for(int j = i; j < s.size(); j++){
            if (isPalindrome(s, i, j)) {
                path.push_back(s.substr(i, j-i+1));
                dfs(s, j+1, path);
                path.pop_back();
            }
    }
}

bool isPalindrome(string& s, int left, int right){
    while (left < right){
        if(s[left] != s[right] )return false;
        left++;
        right--;
    }
    return true;
}
};
