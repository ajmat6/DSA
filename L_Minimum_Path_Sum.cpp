class Solution {
public:
    // Recursion: Gives TLE
    int solve(vector<vector<int>>& grid, int row, int column)
    {
        // Base Case:
        if(row == grid.size()-1 && column == grid[0].size()-1) return grid[row][column];

        // Down Move:
        int ans = INT_MAX;
        if(row+1 < grid.size())
        {
            ans = min(ans, grid[row][column] + solve(grid, row+1, column));
        }

        // Right Move:
        int ans2 = INT_MAX;
        if(column+1 < grid[0].size())
        {
            ans = min(ans, grid[row][column] + solve(grid, row, column+1));
        }

        return ans;
    }

    // Memorisation:
    int solve2(vector<vector<int>>& grid, int row, int column, vector<vector<int>>& dp)
    {
        // Base Case:
        if(row == grid.size()-1 && column == grid[0].size()-1) return grid[row][column];

        // Checking for dp:
        if(dp[row][column] != -1) return dp[row][column];

        // Down Move:
        int ans = INT_MAX;
        if(row+1 < grid.size())
        {
            ans = min(ans, grid[row][column] + solve2(grid, row+1, column, dp));
        }

        // Right Move:
        int ans2 = INT_MAX;
        if(column+1 < grid[0].size())
        {
            ans = min(ans, grid[row][column] + solve2(grid, row, column+1, dp));
        }

        // Storing ans in dp:
        dp[row][column] = ans;

        return ans;
    }

    int solve3(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Creating 2d dp:
        vector<vector<int>> dp (n, vector<int> (m, 0));

        // Handling recursive cases:
        for(int row=n-1; row>=0; row--)
        {
            for(int column=m-1; column>=0; column--)
            {
                if(row == n-1 && column == m-1) dp[row][column] = grid[row][column];

                else
                {
                    if(row == n-1)
                    {
                        dp[row][column] = grid[row][column] + dp[row][column+1];
                    }

                    else if(column == m-1)
                    {
                        dp[row][column] = grid[row][column] + dp[row+1][column];
                    }

                    else
                    {
                        dp[row][column] = grid[row][column] + min(dp[row][column+1], dp[row+1][column]);
                    }
                }
            }
        }

        return dp[0][0];
    }

    // Space Optimisation:
    int solve4(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Creating 2d dp:
        // vector<vector<int>> dp (n, vector<int> (m, 0));
        vector<int> curr (m, 0);
        vector<int> next (m, 0);

        // Handling recursive cases:
        for(int row=n-1; row>=0; row--)
        {
            for(int column=m-1; column>=0; column--)
            {
                if(row == n-1 && column == m-1) curr[column] = grid[row][column];

                else
                {
                    if(row == n-1)
                    {
                        curr[column] = grid[row][column] + curr[column+1];
                    }

                    else if(column == m-1)
                    {
                        curr[column] = grid[row][column] + next[column];
                    }

                    else
                    {
                        curr[column] = grid[row][column] + min(curr[column+1], next[column]);
                    }
                }
            }

            next = curr;
        }

        return next[0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        // return solve(grid, 0, 0);

        // Memorisation:
        // vector<vector<int>> dp (grid.size()+1, vector<int> (grid[0].size()+1, -1));
        // return solve2(grid, 0, 0, dp);

        // Tabulation:
        // return solve3(grid);

        // Space Optimisation:
        return solve4(grid);
    }
};