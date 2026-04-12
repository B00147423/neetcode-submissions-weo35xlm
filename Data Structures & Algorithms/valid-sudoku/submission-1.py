
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Use dictionaries to track seen numbers in rows, columns, and 3x3 squares
        cols = collections.defaultdict(set)  # Tracks numbers in each column
        rows = collections.defaultdict(set)  # Tracks numbers in each row
        squares = collections.defaultdict(set)  # Tracks numbers in each 3x3 square, keyed by (r // 3, c // 3)

        for r in range(9):  # Loop through rows
            for c in range(9):  # Loop through columns
                if board[r][c] == ".":  # Skip empty cells
                    continue
                # Check if the current number already exists in the row, column, or square
                if (board[r][c] in rows[r] or  # Number exists in the current row
                    board[r][c] in cols[c] or  # Number exists in the current column
                    board[r][c] in squares[(r // 3, c // 3)]):  # Number exists in the current 3x3 square
                    return False  # Sudoku is invalid if duplicate is found

                # Add the current number to the appropriate row, column, and square
                cols[c].add(board[r][c])
                rows[r].add(board[r][c])
                squares[(r // 3, c // 3)].add(board[r][c])
        
        # If no duplicates are found, the Sudoku is valid
        return True