class Solution {
public:
    int solve(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if(dp[row][col] != -1) return dp[row][col];

        int ans = 1;
        // traversing four possible directions:
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i=0; i<4; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && matrix[newRow][newCol] > matrix[row][col])
            {
                ans = max(ans, 1 + solve(matrix, newRow, newCol, dp));
            }
        }

        dp[row][col] = ans;

        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // int ans =  1;
        // vector<vector<int>> dp (matrix.size(), vector<int> (matrix[0].size(), -1));
        // for(int i=0; i<matrix.size(); i++)
        // {
        //     for(int j=0; j<matrix[0].size(); j++)
        //     {
        //         ans = max(ans, solve(matrix, i, j, dp));
        //     }
        // }
        // return ans;

        // Topological sort:

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> indegree (n, vector<int> (m, 0));
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int dr[4] = {-1, 0, 1, 0};
                int dc[4] = {0, 1, 0, -1};
                for(int k=0; k<4; k++)
                {
                    int newRow = i + dr[k];
                    int newCol = j + dc[k];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && matrix[newRow][newCol] < matrix[i][j])
                    {
                        indegree[i][j]++;
                    }
                }
                
                // if indegree of this particular block is 0, then pusb it into the queue:
                if(indegree[i][j] == 0) q.push({i, j});
            }

        }

        int ans = 0;
        while(!q.empty())
        {
            int size =  q.size();
            while(size--)
            {
                auto front = q.front();
                q.pop();

                int row = front.first;
                int col = front.second;

                int dr[4] = {-1, 0, 1, 0};
                int dc[4] = {0, 1, 0, -1};
                for(int k=0; k<4; k++)
                {
                    int newRow = row + dr[k];
                    int newCol = col + dc[k];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && matrix[newRow][newCol] > matrix[row][col])
                    {
                        indegree[newRow][newCol]--;
                        if(indegree[newRow][newCol] == 0) q.push({newRow, newCol});
                    }
                }
            }
            ans++;
        }

        return ans;
    }
};
