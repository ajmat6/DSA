class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int solve(vector<vector<int>>& grid, int row, int col) {
        int temp = grid[row][col];
        int ans = temp;
        grid[row][col] = 0;
        for(int i=0; i<4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] != 0) ans = max(ans, temp + solve(grid, newRow, newCol));
        }
        grid[row][col] = temp; // backtrack
        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] != 0) ans = max(ans, solve(grid, i, j));
            }
        }
        return ans;
    }
};