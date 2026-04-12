class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> myMap;

        for (int num : nums) {
            if (num > 0) myMap[num] = true;
        }

        int i = 1;
        while (true) {
            if (myMap.find(i) == myMap.end()) {
                return i;
            }
            i++;
        }

        return 0; 
    }
};