class Solution {
    vector<string> result;
    vector<pair<char,char>> pairs = {
        {'0','0'},
        {'1','1'},
        {'6','9'},
        {'8','8'},
        {'9','6'}
    };

public:
    vector<string> findStrobogrammatic(int n) {
        string curr(n, ' ');
        backtrack(curr, 0, n - 1);
        return result;
    }

private:
    void backtrack(string& curr, int l, int r) {
        if (l > r) {
            result.push_back(curr);
            return;
        }

        for (const auto& p : pairs) {
            char a = p.first;
            char b = p.second;

            // no leading zero
            if (l == 0 && a == '0' && curr.size() > 1) continue;

            // middle position must match itself
            if (l == r && a != b) continue;

            curr[l] = a;
            curr[r] = b;

            backtrack(curr, l + 1, r - 1);
        }
    }
};

