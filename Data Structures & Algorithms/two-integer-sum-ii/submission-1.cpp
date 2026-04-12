class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
            unordered_map<int, int> numMap;

            // Iterate through the numbers
            for (int i = 0; i < numbers.size(); i++) {
                // Calculate the complement
                int complement = target - numbers[i];

                // Check if the complement exists in the map
                if (numMap.find(complement) != numMap.end()) {
                    // If found, return the indices (1-based)
                    return {numMap[complement] + 1, i + 1};
                }

                // Store the index of the current number in the map
                numMap[numbers[i]] = i;
            }
    }
};
