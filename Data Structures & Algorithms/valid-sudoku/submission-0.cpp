class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    // Use 9 sets for rows, columns, and sub-boxes
    std::vector<std::unordered_set<char>> rows(9);
    std::vector<std::unordered_set<char>> cols(9);
    std::vector<std::unordered_set<char>> boxes(9);
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char num = board[i][j];
            if (num != '.') {
                // Calculate the index for the 3x3 sub-box
                int boxIndex = (i / 3) * 3 + (j / 3);
                
                // Check row, column, and box for duplicates
                if (rows[i].find(num) != rows[i].end() ||
                    cols[j].find(num) != cols[j].end() ||
                    boxes[boxIndex].find(num) != boxes[boxIndex].end()) {
                    return false;
                }
                
                // Add number to row, column, and box sets
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxIndex].insert(num);
            }
        }
    }
    }
};
