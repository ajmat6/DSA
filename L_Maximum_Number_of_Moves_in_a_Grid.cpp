class Solution {
public:
    bool isValid(int& row, int& col, int& n, int& m) {
        if(row >= 0 && row < n && col >= 0 && col < m) return true;
        return false;
    }

    int dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(dp[row][col] != -1) return dp[row][col];

        int maxMoves = 0;
        for(int i=-1; i<=1; i++) {
            int newRow = row + i;
            int newCol = col + 1;
            if(isValid(newRow, newCol, n, m) && grid[newRow][newCol] > grid[row][col]) {
                maxMoves = max(maxMoves, 1 + dfs(grid, newRow, newCol, dp));
            }
        }
        return dp[row][col] = maxMoves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<int>> dp (n + 1, vector<int> (m + 1, -1));
        for(int i=0; i<n; i++) {
            ans = max(ans, dfs(grid, i, 0, dp));
        }

        return ans;
    }
};
