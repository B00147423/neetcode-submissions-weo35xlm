class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for(int i = 0; i < s.size(); i++){
            res += countPali(s, i, i);
            res += countPali(s, i, i+1);
        }
        return res;
    }

private:
    int countPali(string s, int left, int right){
        int res = 0;

        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            res++;
            left--;
            right++;
        }
        return res;
    }
};
