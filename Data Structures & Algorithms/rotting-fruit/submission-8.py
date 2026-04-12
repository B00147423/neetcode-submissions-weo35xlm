class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:

        ROWS, COLS = len(grid), len(grid[0])

        def dfs(r, c, rottenTimeTaken):
            if (
                r < 0 or r >= ROWS or
                c < 0 or c >= COLS or
                grid[r][c] == 0
            ):
                return

            if grid[r][c] != 1 and grid[r][c] < rottenTimeTaken:
                return

            grid[r][c] = rottenTimeTaken

            dfs(r + 1, c, rottenTimeTaken + 1)
            dfs(r - 1, c, rottenTimeTaken + 1)
            dfs(r, c + 1, rottenTimeTaken + 1)
            dfs(r, c - 1, rottenTimeTaken + 1)

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 2:
                    dfs(r, c, 2)

        maxTime = 2
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    return -1
                maxTime = max(maxTime, grid[r][c])

        return maxTime - 2