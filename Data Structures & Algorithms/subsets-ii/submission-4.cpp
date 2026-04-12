
class Solution {
    vector<vector<int>> res;
public:
    vector<vector< int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // important for duplicate handling
        vector<int> curr;
        backtrack(nums, 0, curr);
        return res;
    }
private:
    void backtrack(vector<int>& nums, int start, vector<int>& curr) {
        //base case
        res.push_back(curr);
        //loop over nums push the first subset 
        for(int i = start; i < nums.size(); i++)
        {
            //check if the path is used first
            if (i > start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr);  // move forward
            curr.pop_back();
        }
    }

}; 

//01222
//01210 = start

