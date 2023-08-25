class Solution {
public:
    void DFS(vector<vector<char>>& board, vector<vector<int>>& isVisited, int row, int column)
    {
        int n = board.size();
        int m = board[0].size();

        // marking curr index DFS call as visited:
        isVisited[row][column] = true;

        // checking for all four adjacent indexes:
        for(int posRow=-1; posRow<=1; posRow++)
            {
                for(int posCol=-1; posCol<=1; posCol++)
                {
                    // skip for diagonal adjacent indexes:
                    if(abs(posRow) + abs(posCol) == 2) continue;

                    int nextRow = row + posRow;
                    int nextCol = column + posCol;

                    if(nextRow >=0 && nextRow <  n && nextCol >=0 && nextCol < m && board[nextRow][nextCol] == 'O' && !isVisited[nextRow][nextCol])
                    {
                        DFS(board, isVisited, nextRow, nextCol);
                    }
                }
            }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> isVisited (n, vector<int> (m, 0));

        // Traversing for the border indexes:
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // skip if curr index is not a border index:
                if(i != 0 && i != n-1 && j != 0 && j != m-1) continue;

                // if curr is border index, check if 'O' is present and it should not be visited:
                if(board[i][j] == 'O' && !isVisited[i][j])
                {
                    DFS(board, isVisited, i, j);
                }
            }
        }

        // till here all connected zeros to border 0 are visited, now traverse and if any unvisited zero is found convert it to 'X':
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == 'O' && !isVisited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};