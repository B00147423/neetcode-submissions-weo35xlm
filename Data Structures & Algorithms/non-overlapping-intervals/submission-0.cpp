class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {


        sort(intervals.begin(), intervals.end());
        int res = 0;

        // take the end of the first interval
        int prevEnd = intervals[0][1];// 2

        // start from the second interval (i = 1)
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];// 2
            int end   = intervals[i][1];

            if (start >= prevEnd) {
                // no overlap → keep the interval
                prevEnd = end; //becoems next interval // 2
            } else {
                // overlap → remove one interval
                res++;
                // keep the interval with the smaller end
                prevEnd = min(prevEnd, end);
            }
        }
        return res;
    }
};
