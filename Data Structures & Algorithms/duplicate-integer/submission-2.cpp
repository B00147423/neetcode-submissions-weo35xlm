class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        vector<int> numCount;
        for (int i = 0; i < nums.size(); i++) {
            // Check if nums[i] is already in numCount
            if (find(numCount.begin(), numCount.end(), nums[i]) != numCount.end()) {
                return true; // Found a duplicate
            }
            // If not, add it to numCount
            numCount.push_back(nums[i]);
        }
        return false; // No duplicates found
    }
};