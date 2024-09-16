class Solution {
public:
    int memorisation(int n, int m, int row, int col, vector<vector<int>>& dp) {
        if(row == n - 1 && col == m - 1) return 1;
        if(dp[row][col] != -1) return dp[row][col];

        int ans = 0;
        if(col + 1 <= m - 1) ans += memorisation(n, m, row, col + 1, dp);
        if(row + 1 <= n - 1) ans += memorisation(n, m, row + 1, col, dp);
        return dp[row][col] = ans;
    }

    int tabulation(int n, int m) {
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));
        dp[n - 1][m - 1] = 1;

        for(int row=n-1; row>=0; row--) {
            for(int col=m-1; col>=0; col--) {
                if(row == n - 1 && col == m - 1) continue;
                int ans = 0;
                if(col + 1 <= m - 1) ans += dp[row][col + 1];
                if(row + 1 <= n - 1) ans += dp[row + 1][col];
                dp[row][col] = ans;
            }
        }
        return dp[0][0];
    }

    int spaceOptimisation(int n, int m) {
        vector<int> curr (m + 1, 0);
        vector<int> next (m + 1, 0);
        curr[m - 1] = 1;

        for(int row=n-1; row>=0; row--) {
            for(int col=m-1; col>=0; col--) {
                if(row == n - 1 && col == m - 1) continue;
                int ans = 0;
                if(col + 1 <= m - 1) ans += curr[col + 1];
                if(row + 1 <= n - 1) ans += next[col];
                curr[col] = ans;
            }
            next = curr;
        }
        return curr[0];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m + 1, vector<int> (n + 1, -1));
        return memorisation(m, n, 0, 0, dp);

        // return tabulation(m, n);
        return spaceOptimisation(m, n);
    }
};