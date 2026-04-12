class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        dfs(nums, 0, current, 0, target);
        return res;
    }

    void dfs(vector<int>& nums, int i, vector<int>& current, int total, int target) {
        if (total == target) {
            res.push_back(current);
            return;
        }
        if (i >= nums.size() || total > target) {
            return;
        }

        //choose nums[i]
        current.push_back(nums[i]);
        dfs(nums, i, current, total + nums[i], target); // stay on i (can reuse same number)
        current.pop_back();

        // skip nums[i]
        dfs(nums, i + 1, current, total, target);
    }
};