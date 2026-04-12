class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ROWS, COLS = len(board), len(board[0])

        def dfs(r, c, i):
            if i == len(word):
                return True
            if (r < 0 or c < 0 or r >= ROWS or c >= COLS or
                word[i] != board[r][c] or board[r][c] == '#'):
                return False

            board[r][c] = '#'
            res = (dfs(r + 1, c, i + 1) or # backtrack row 1 col 0 
                   dfs(r - 1, c, i + 1) or # backtrack row 2 col 0 
                   dfs(r, c + 1, i + 1) or
                   dfs(r, c - 1, i + 1))
            board[r][c] = word[i]
            return res

            '''
            [
            ["A","B","C","D"],  (dfs(r + 1, c, i + 1)   backtrack r+1 = s c = 0 
            ["S","A","A","T"],   dfs(r - 1, c, i + 1)  backtrack r-1 = A  2 col 0 
            ["A","C","A","E"]  dfs(r, c + 1, i + 1)backtrac 
            ]


            res = (dfs(r + 1, c, i + 1) or # backtrack r+1 = s c = 0 
            dfs(r - 1, c, i + 1) or # backtrack r-1 = A  2 col 0 
            dfs(r, c + 1, i + 1) or #  backtrac  row = A col+1 makes it 2nd column 
            dfs(r, c - 1, i + 1))
            '''

        for r in range(ROWS):
            for c in range(COLS):
                if dfs(r, c, 0):
                    return True
        return False