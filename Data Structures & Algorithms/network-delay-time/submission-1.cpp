class Solution {

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;

        // build adjacency list using "time is always last element"
        for (auto& t : times) {
            int from = t.front();   // first element
            int to   = t[1];        // middle element
            int cost = t.back();    // last element (time)
            edges[from].emplace_back(to, cost);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        minHeap.push({0, k}); // (time=0, start node)

        unordered_set<int> visited;
        int t = 0;

        while (!minHeap.empty()) {
            auto [currTime, node] = minHeap.top();
            minHeap.pop();

            if (visited.count(node)) continue;
            visited.insert(node);
            t = currTime;

            for (auto& [next, travel] : edges[node]) {
                if (!visited.count(next)) {
                    minHeap.push({currTime + travel, next});
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};
