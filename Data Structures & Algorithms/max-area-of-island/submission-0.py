class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        '''
     island = group of 1s conencted horizontally or vertically 

     assume all 4 edges of grid are surroounded by water
    
     area of cells = num of cells within island

        '''
    
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        ROWS, COLS = len(grid), len(grid[0])
        maxArea = 0
        if not grid:
                return 0
        def dfs(r, c):
            if r < 0 or c < 0 or r >= ROWS or c >= COLS or grid[r][c] == 0:
                return 0
            grid[r][c] = 0 # mark as visited
            area = 1  # current cell

            
            for dr, dc in directions:
                area += dfs(r + dr, c + dc)
            return area

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    maxArea = max(maxArea, dfs(r, c))
        return maxArea

