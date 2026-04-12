class Solution {
  
public:
    bool makesquare(vector<int>& matchsticks) {
        long long sum;
        sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0LL);

        if (sum % 4 != 0) return false;
        int target = sum / 4;
        vector<int> sides(4, 0);
        // target now exists so recursion can USE it later
        return backtrack(matchsticks, sides, 0, target);
    }
private:
    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int index, int target){
        if (index == matchsticks.size()){
            return true;
        }

            for (int i = 0; i < 4; i++) {
                if (sides[i] + matchsticks[index] <= target) {
                    sides[i] += matchsticks[index];
                    if (backtrack(matchsticks, sides, index + 1, target)){
                        return true;
                    }
                    sides[i] -= matchsticks[index];
                }

                if (sides[i] == 0) break; // avoid duplicate work
            }

        return false;
    }
};