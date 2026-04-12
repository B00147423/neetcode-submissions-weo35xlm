class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<bool>> pacificOcean(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlanticOcean(ROWS, vector<bool>(COLS, false));


        for (int c = 0; c < COLS; ++c) {
            dfs(0, c, pacificOcean, heights);
            dfs(ROWS - 1, c, atlanticOcean, heights);
        }
        for (int r = 0; r < ROWS; ++r) {
            dfs(r, 0, pacificOcean, heights);
            dfs(r, COLS - 1, atlanticOcean, heights);
        }

        vector<vector<int>> res;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pacificOcean[r][c] && atlanticOcean[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }

private:
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;
        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < heights.size() &&
                nc >= 0 && nc < heights[0].size() &&
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
};
