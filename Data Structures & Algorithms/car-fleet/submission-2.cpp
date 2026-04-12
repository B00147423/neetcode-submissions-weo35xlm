class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /* 
        /(target - POSITION) / SPEED = for calculating the tiem it takes to reach target 


        */    
        int n = position.size();
        vector<pair<int, int>> pair;

        for(int i = 0; i < n; i ++){
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<double> stack;
        for (auto& p : pair) {
            stack.push_back((double)(target - p.first) / p.second);
            if (stack.size() >= 2 && 
                stack.back() <= stack[stack.size() - 2]) 
            {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};
