class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> res;
        for (int n:nums) {
            if(res.count(n)){
                return true;
            }
            res.insert(n);
        }
        return false;
    }
};
