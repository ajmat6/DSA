class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Base case:
        if(i == m-1)
        {
            return matrix[i][j];
        }

        int ans = INT_MAX;
        int rightDiagonal = INT_MAX;
        int leftDiagonal = INT_MAX;
        int Down = INT_MAX;

        // right diagonal move:
        if(i+1 < m && j-1 >= 0)
        {
            leftDiagonal = matrix[i][j] + solve(matrix, i+1, j-1);
        }

        // left diagonal move:
        if(i+1 < m && j+1 < n)
        {
            rightDiagonal = matrix[i][j] + solve(matrix, i+1, j+1);
        }

        // down move:
        if(i+1 < m)
        {
            Down = matrix[i][j] + solve(matrix, i+1, j);
        }

        ans = min(ans, min(rightDiagonal, min(leftDiagonal, Down)));

        return ans;
    }

    int solve2(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Base case:
        if(i == m-1)
        {
            return matrix[i][j];
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        int rightDiagonal = INT_MAX;
        int leftDiagonal = INT_MAX;
        int Down = INT_MAX;

        // right diagonal move:
        if(i+1 < m && j-1 >= 0)
        {
            leftDiagonal = matrix[i][j] + solve2(matrix, i+1, j-1, dp);
        }

        // left diagonal move:
        if(i+1 < m && j+1 < n)
        {
            rightDiagonal = matrix[i][j] + solve2(matrix, i+1, j+1, dp);
        }

        // down move:
        if(i+1 < m)
        {
            Down = matrix[i][j] + solve2(matrix, i+1, j, dp);
        }

        ans = min(ans, min(rightDiagonal, min(leftDiagonal, Down)));

        dp[i][j] = ans;

        return ans;
    }

    // Tabulation:
    int solve3(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = INT_MAX;

        vector<vector<int>> dp (m, vector<int> (n, 0));

        // Handling base case:
        for(int j=0; j<n; j++)
        {
            dp[m-1][j] = matrix[m-1][j];
        }

        // Handling rest of the recursive cases:
        for(int i=m-2; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                int ans = INT_MAX;
                int rightDiagonal = INT_MAX;
                int leftDiagonal = INT_MAX;
                int Down = INT_MAX;

                // right diagonal move:
                if(i+1 < m && j-1 >= 0)
                {
                    leftDiagonal = matrix[i][j] + dp[i+1][j-1];
                }

                // left diagonal move:
                if(i+1 < m && j+1 < n)
                {
                    rightDiagonal = matrix[i][j] + dp[i+1][j+1];
                }

                // down move:
                if(i+1 < m)
                {
                    Down = matrix[i][j] + dp[i+1][j];
                }

                ans = min(ans, min(rightDiagonal, min(leftDiagonal, Down)));

                dp[i][j] = ans;
            }
        }

        // checking for min sum from each index of first row:
        for(int index=0; index<n; index++)
        {
            mini = min(mini, dp[0][index]);
        }

        return mini;
    }

    // Tabulation:
    int solve4(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = INT_MAX;

        vector<int> curr (n, 0);
        vector<int> next (n, 0);

        // Handling base case:
        for(int j=0; j<n; j++)
        {
            next[j] = matrix[m-1][j];
        }

        // Handling rest of the recursive cases:
        for(int i=m-2; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                int ans = INT_MAX;
                int rightDiagonal = INT_MAX;
                int leftDiagonal = INT_MAX;
                int Down = INT_MAX;

                // right diagonal move:
                if(i+1 < m && j-1 >= 0)
                {
                    leftDiagonal = matrix[i][j] + next[j-1];
                }

                // left diagonal move:
                if(i+1 < m && j+1 < n)
                {
                    rightDiagonal = matrix[i][j] + next[j+1];
                }

                // down move:
                if(i+1 < m)
                {
                    Down = matrix[i][j] + next[j];
                }

                ans = min(ans, min(rightDiagonal, min(leftDiagonal, Down)));

                curr[j] = ans;
            }

            next = curr;
        }

        for(int index=0; index<n; index++)
        {
            mini = min(mini, next[index]);
        }

        return mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int mini = INT_MAX;
        // for(int i=0; i<matrix[0].size(); i++)
        // {
        //     mini = min(mini, solve(matrix, 0, i));
        // }

        // return mini;

        // Memorisation:
        // int mini = INT_MAX;
        // vector<vector<int>> dp (matrix.size(), vector<int> (matrix[0].size(), -1));
        // for(int i=0; i<matrix[0].size(); i++)
        // {
        //     mini = min(mini, solve2(matrix, 0, i, dp));
        // }

        // return mini;

        // Tabulation:
        return solve3(matrix);

        // Space Optimisation:
        // return solve4(matrix);
    }
};