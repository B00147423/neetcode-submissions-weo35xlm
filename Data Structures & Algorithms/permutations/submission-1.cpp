class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        backtrack(nums, curr, used);
        return res;
    
    }

private:
    void backtrack(vector<int>& nums, vector<int>& curr_path, vector<bool>& used_path){
        if(curr_path.size() == nums.size()){
            res.push_back(curr_path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) { 
            if (used_path[i]) continue;
            used_path[i] = true;
            curr_path.push_back(nums[i]);
            backtrack(nums, curr_path, used_path);
            curr_path.pop_back();
            used_path[i] = false;
        }
    }

};
