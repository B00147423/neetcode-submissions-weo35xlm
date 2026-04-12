class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

    vector<int> prices(n, INT_MAX);
    prices[src] = 0;
    vector<vector<pair<int, int>>> adj(n);
    //Shortest Path Faster Algorithm
    for (const auto& flight : flights){
        adj[flight[0]].emplace_back(flight[1], flight[2]);
    }

    queue<tuple<int, int, int>> q;
    //First 0 → total cost so far
    //Second 0 → current airport (src)
    //Third 0 → number of stops taken so far
    q.push({0, src, 0});


    while(!q.empty()){
        auto [cst, node, stops] = q.front();
        q.pop();

        if(stops > k){
            continue;
        }

        for(const auto& neighbor : adj[node]){
            int nei = neighbor.first, w = neighbor.second;
            cout << " nei : " <<nei << "\nw: " << w;
            int nextCost = cst + w;
            if(nextCost <  prices[nei]){
                prices[nei] = nextCost;
                q.push({nextCost, nei, stops+1});
            }
        }
    }
    return prices[dst] == INT_MAX ? -1 : prices[dst];
    }

};
