class Solution {
public:
    int recursion(int m, int n, int row, int column)
    {
        if(row == m && column == n) return 1;

        // Right side:
        int right = 0;
        if(column + 1 <= n)
        {
            right = recursion(m, n, row, column+1);
        }

        // Down side:
        int down = 0;
        if(row + 1 <= m)
        {
            down = recursion(m, n, row+1, column);
        }

        int ans = right + down;
        return ans;
    }

    int memo(int m, int n, int row, int column, vector<vector<int>>& dp)
    {
        if(row == m && column == n) return 1;

        if(dp[row][column] != -1) return dp[row][column];

        // Right side:
        int right = 0;
        if(column + 1 <= n)
        {
            right = memo(m, n, row, column+1, dp);
        }

        // Down side:
        int down = 0;
        if(row + 1 <= m)
        {
            down = memo(m, n, row+1, column, dp);
        }

        int ans = right + down;

        // storing in dp:
        dp[row][column] = ans;

        return ans;
    }

    int tab(int m, int n)
    {
        vector<vector<int>> dp (m+1, vector<int> (n+1, 0));

        // Handling base case:
        dp[m][n] = 1;

        for(int row=m; row>=1; row--)
        {
            for(int column=n; column>=1; column--)
            {
                // as we already handled the base case:
                if(row == m && column == n) continue;

                // Right side:
                int right = 0;
                if(column + 1 <= n)
                {
                    right = dp[row][column+1];
                }

                // Down side:
                int down = 0;
                if(row + 1 <= m)
                {
                    down = dp[row+1][column];
                }

                int ans = right + down;

                // storing in dp:
                dp[row][column] = ans;
            }
        }

        return dp[1][1];
    }

    int spaceOptimize(int m, int n)
    {
        vector<int> curr (n+1, 0);
        vector<int> next (n+1, 0);

        // Handling base case:
        next[n] = 1;
        curr[n] = 1;

        for(int row=m; row>=1; row--)
        {
            for(int column=n; column>=1; column--)
            {
                if(row == m && column == n) continue;

                // Right side:
                int right = 0;
                if(column + 1 <= n)
                {
                    right = curr[column+1];
                }

                // Down side:
                int down = 0;
                if(row + 1 <= m)
                {
                    down = next[column];
                }

                int ans = right + down;

                // storing in dp:
                curr[column] = ans;
            }

            next = curr;
        }

        return next[1];
    }

    int uniquePaths(int m, int n) {
        // return recursion(m, n, 1, 1);

        // Memorisation:
        // vector<vector<int>> dp (m+1, vector<int> (n+1, -1));
        // return memo(m, n, 1, 1, dp);

        // Tabulation:
        // return tab(m, n);

        // Space Optimisation:
        return spaceOptimize(m, n);
    }
};
