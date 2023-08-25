class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> isVisited (n, vector<int> (m, 0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // skip non border indexes:
                if(i != 0 && i != n-1 && j != 0 && j != m-1) continue;

                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                    isVisited[i][j] = true;
                }
            }
        }

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // treversing all four direction around an index:
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    // skip diagonal move:
                    if(abs(i) + abs(j) == 2) continue;

                    int newRow = row + i;
                    int newCol  = col + j;

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !isVisited[newRow][newCol])
                    {
                        q.push({newRow, newCol});
                        isVisited[newRow][newCol] = true;
                    }
                }
            }
        }

        // couting one's that are not yet visited:
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1 && !isVisited[i][j]) ans++;
            }
        }

        return ans;
    }
};