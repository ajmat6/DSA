class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int column, int n)
    {
        // Base Case:
        if(row == n-1) return triangle[row][column];

        int ans = INT_MAX;

        // Down Move:
        if(row+1 <= n-1)
        {
            ans = min(ans, solve(triangle, row+1, column, n) + triangle[row][column]);
        }

        // Adjacent Move:
        if(row+1 <= n-1 && column+1 < triangle[row+1].size())
        {
            ans = min(ans, solve(triangle, row+1, column+1, n) + triangle[row][column]);
        }

        return ans;
    }

    // Memorisation:
    int solve2(vector<vector<int>>& triangle, int row, int column, int n, vector<vector<int>>& dp)
    {
        // Base Case:
        if(row == n-1) return triangle[row][column];

        // checking for dp:
        if(dp[row][column] != -1) return dp[row][column];

        int ans = INT_MAX;

        // Down Move:
        if(row+1 <= n-1)
        {
            ans = min(ans, solve2(triangle, row+1, column, n, dp) + triangle[row][column]);
        }

        // Adjacent Move:
        if(row+1 <= n-1 && column+1 < triangle[row+1].size())
        {
            ans = min(ans, solve2(triangle, row+1, column+1, n, dp) + triangle[row][column]);
        }

        // Store in dp:
        dp[row][column] = ans;

        return ans;
    }

    // Tabulation:
    int solve3(vector<vector<int>>& triangle, int n)
    {
        int lastRowLength = triangle[n-1].size();
        // Creating a 2d dp:
        vector<vector<int>> dp (n, vector<int> (lastRowLength, 0));

        // Base Case Handle:
        for(int i=0; i<triangle[n-1].size(); i++)
        {
            dp[n-1][i] = triangle[n-1][i];
        }

        // Handling rest of the recursive cases:
        for(int row=n-2; row>=0; row--)
        {
            for(int column=row; column>=0; column--)
            {
                int ans = INT_MAX;

                // Down Move:
                if(row+1 <= n-1)
                {
                    ans = min(ans, dp[row+1][column] + triangle[row][column]);
                }

                // Adjacent Move:
                if(row+1 <= n-1 && column+1 < triangle[row+1].size())
                {
                    ans = min(ans, dp[row+1][column+1] + triangle[row][column]);
                }

                dp[row][column] = ans;
            }
        }

        return dp[0][0];
    }

    // Space Optimisation:
    int solve4(vector<vector<int>>& triangle, int n)
    {
        int lastRowLength = triangle[n-1].size();
        // Creating a 1d dp:
        vector<int> curr (lastRowLength, 0);
        vector<int> next (lastRowLength, 0);

        // Base case Handle:
        for(int i=0; i<triangle[n-1].size(); i++)
        {
            next[i] = triangle[n-1][i];
        }

        // Handling rest of the recursive cases:
        for(int row=n-2; row>=0; row--)
        {
            for(int column=row; column>=0; column--)
            {
                int ans = INT_MAX;

                // Down Move:
                if(row+1 <= n-1)
                {
                    ans = min(ans, next[column] + triangle[row][column]);
                }

                // Adjacent Move:
                if(row+1 <= n-1 && column+1 < triangle[row+1].size())
                {
                    ans = min(ans, next[column+1] + triangle[row][column]);
                }

                curr[column] = ans;
            }

            next = curr;
        }

        return next[0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        // return solve(triangle, 0, 0, triangle.size());

        // Memorisation:
        // int n = triangle.size();
        // int lastRowLength = triangle[n-1].size();
        // vector<vector<int>> dp (n+1, vector<int> (lastRowLength+1, -1));
        // return solve2(triangle, 0, 0, n, dp);

        // Tabulation:
        // int n = triangle.size();
        // return solve3(triangle, n);

        // Space Optimisation:
        int n = triangle.size();
        return solve4(triangle, n);
    }
};