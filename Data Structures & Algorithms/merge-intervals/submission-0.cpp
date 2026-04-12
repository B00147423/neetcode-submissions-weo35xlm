class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);


        for (auto& interval : intervals) {
            int start = interval[0];//1 // 1 // 6
     
            int end = interval[1]; //3 // 5 //  //7

            int lastEnd = output.back()[1];// 3  // 5
                //1 <=    3 IT IS
            if (start <= lastEnd) {
                output.back()[1] = max(lastEnd, end); // THIS IS STILL 1, 3? //push 5 make sit 1,5
            } else {
                output.push_back({start, end});
            }
        }
        return output;
    }
};
