class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        if(triplets.size() == 0 ) return false;
         int max0 = 0, max1 = 0, max2 = 0;
        for(auto &t : triplets){
            int x = t[0];
            int y = t[1];
            int z = t[2];
            if(x  <= target[0] && y <= target[1] && z <= target[2]){
                max0 = max(max0, x);
                max1 = max(max1, y);
                max2 = max(max2, z);
            }
        }

    return max0 == target[0] && max1 == target[1] && max2 == target[2];
    }
};
