class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        //base case if nums is emtpy rerturn
       if (nums.empty()) return {{}};
       vector<int> path;
       backtrack(nums, 0, path);
       return res;
    }
private:
    void backtrack(vector<int>& nums, int start, vector<int>& path){
   
        res.push_back(path);
        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);          // choose nums[i]
            backtrack(nums, i + 1, path);
            path.pop_back(); 
        }
    }
};
