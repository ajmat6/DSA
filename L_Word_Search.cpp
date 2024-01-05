class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int row, int col, int index)
    {
        int n = board.size();
        int m = board[0].size();

        if(index == word.size()) return true;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int i=0; i<4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && board[newRow][newCol] == word[index])
            {
                board[newRow][newCol] = '#';
                bool temp = solve(board, word, newRow, newCol, index+1);
                if(temp) return true;
                else board[newRow][newCol] = word[index];  // backtrack
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == word[0])
                {
                    board[i][j] = '#';
                    bool ans = solve(board, word, i, j, 1);
                    if(ans) return true;
                    board[i][j] = word[0];
                }
            }
        }

        return false;
    }
};