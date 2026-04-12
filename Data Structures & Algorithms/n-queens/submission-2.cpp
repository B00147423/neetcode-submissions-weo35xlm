class Solution {
    vector<string> board;

    vector<bool> col,  positiveDiag, negativeDiag;
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n, false);
        positiveDiag.resize(2 * n, false);
        negativeDiag.resize(2 * n, false);
        board.resize(n, string(n, '.'));
        backtrack(0, n);
        return res;
    }
private:

    void backtrack(int r, int & n){
        if (r == n){
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++){
            if (col[c] || positiveDiag[r+c] || negativeDiag[r-c+n]){
                continue;
            }
               
          

            col[c] = true;
            positiveDiag[r+c] = true;
            negativeDiag[r-c+n] = true;
            board[r][c] = 'Q';

            backtrack(r+1, n);

            col[c] = false;
            positiveDiag[r+c] = false;
            negativeDiag[r-c+n] = false;
            board[r][c] = '.';

        }
    }
    //use dfs i ndfs we will need row column
};
