// TC is n^n as for each column you can place queen at each row position:
// SC is O(n) for strong board
class Solution {
public:
    bool checkForRowDiagonal(int n, vector<string>& temp, int row, int col) {
        for(int i=0; i<col; i++) {
            if(temp[row][i] == 'Q') return false;
        }

        int currRow = row - 1;
        int currCol = col - 1;
        while(currRow >= 0 && currCol >= 0) {
            if(temp[currRow][currCol] == 'Q') return false;
            currRow -= 1;
            currCol -= 1;
        }

        currRow = row + 1;
        currCol = col - 1;
        while(currRow < n && currCol >= 0) {
            if(temp[currRow][currCol] == 'Q') return false;
            currRow += 1;
            currCol -= 1;
        }
        return true;
    }

    void dfs(int n, vector<vector<string>>& ans, vector<string>& board, int col) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int i=0; i<n; i++) { // poss row value for curr col
            if(checkForRowDiagonal(n, board, i, col)) {
                board[i][col] = 'Q';
                dfs(n, ans, board, col + 1);
                board[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s (n, '.');
        vector<string> temp (n, s);
        vector<vector<string>> ans;
        dfs(n, ans, temp, 0);
        return ans;
    }
};