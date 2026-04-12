class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        

        /*
        0 water
        1 island
        grid[i] = either  0 water or 1 island
        island = connectd 1, horizontally | or vertically -
        area of island = number of cells in within island

        return maximum area of island in a grid. 0 otherwise if no island

        example:

        Input: grid = [
            [0,1,1,0,1],
            [1,0,1,0,1],
            [0,1,1,0,1],
            [0,1,0,0,1]
        ]

        so we want row and col, 

        for row0 col 0 it;s 0 mvoe forward.

        row0 col1 is 1, means island, we then look at the 4 directions, 
        up down lft right to check if there is another 1, in that cell, 

        we use dfs recursino to do this, 

        */
        int ROW = grid.size();
        int COLS = grid[0].size();
        int area = 0;
        for(int r = 0; r < ROW; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == 1){
                    area = max(area, dfs(grid, r, c));
                }
            }
        }
        return area;
    }

    
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || 
           c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        } //out of boudns, Skip water or visited cells

        grid[r][c] = 0;
        int result = 1;
        for (int i = 0; i < 4; i++) {
            result += dfs(grid, r+ directions[i][0], 
                                c + directions[i][1]);
        }
        return result;
    }
};
