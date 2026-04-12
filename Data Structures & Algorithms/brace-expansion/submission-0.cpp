class Solution {
public:
    vector<string> expand(string s) {
        vector<vector<char>> groups;

        for (int i = 0; i < s.length(); ++i) {
            vector<char> options;

            if (s[i] == '{') {
                i++;
                while (s[i] != '}') {
                    if (isalpha(s[i])) options.push_back(s[i]);
                    i++;
                }
            } else {
                options.push_back(s[i]);
            }

            sort(options.begin(), options.end());
            groups.push_back(options);
        }

        vector<string> result;
        backtrack(0, "", groups, result);
        return result;
    }

private:
    void backtrack(int idx, string current,
                   vector<vector<char>>& groups,
                   vector<string>& result) {
        if (idx == groups.size()) {
            result.push_back(current);
            return;
        }

        for (char c : groups[idx]) {
            backtrack(idx + 1, current + c, groups, result);
        }
    }
};

