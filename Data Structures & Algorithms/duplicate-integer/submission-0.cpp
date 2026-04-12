class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {


        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // Check if nums[i] is already in numCount
            if (nums[i] == nums[i-1]) {
                return true; // Found a duplicate
            }
        }
        return false; // No duplicates found
    }
};