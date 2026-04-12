class Solution {


    unordered_map<string, deque<string>> adj;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //buidl adj lsit 
        for(auto& t: tickets){
            string from = t[0];
            string to = t[1];
            adj[from].push_back(to);
        }

        for(auto& [from, to] : adj){
            sort(to.rbegin(), to.rend());
        }

        vector<string> res;
        dfs("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void dfs(const string& src, unordered_map<string, deque<string>>& adj, vector<string>& res) {

        while(!adj[src].empty()){
            string dst = adj[src].back();
            adj[src].pop_back();
            dfs(dst, adj, res);
        }
        res.push_back(src);

    }
};
