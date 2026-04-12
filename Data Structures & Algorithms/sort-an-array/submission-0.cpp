class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        countingSort(nums);
        return nums;
    }

private:
    void countingSort(vector<int> &arr) {
        unordered_map<int, int> count;
        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());

        for (auto& val : arr) {
            count[val]++;
        }

        int index = 0;
        // Loop over all possible values from the minimum to the maximum
        for (int val = minVal; val <= maxVal; ++val) {

            // Repeat as long as there are occurrences of the current number `val`
            while (count[val] > 0) {

                // Place `val` into the next position of the array
                arr[index] = val;

                // Move the index forward for the next number
                index += 1;

                // Decrease the count since we just placed one occurrence of `val`
                count[val] -= 1;
            }
        }
    }
};