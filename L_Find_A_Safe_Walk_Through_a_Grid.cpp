class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool solve(vector<vector<int>>& grid, int health, int row, int col, vector<vector<vector<int>>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[row][col] == 1) health -= 1;

        if(health <= 0) return false;
        if(row == n - 1 && col == m - 1 && health >= 1) return true;

        for(int i=0; i<4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && vis[newRow][newCol][health] == 0) {
                vis[newRow][newCol][health] = 1;
                if(solve(grid, health, newRow, newCol, vis)) return true;
            }
        }
        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<vector<int>>> vis (grid.size(), vector<vector<int>> (grid[0].size(), vector<int> (health + 1, 0)));
        vis[0][0][health] = 1;
        return solve(grid, health, 0, 0, vis);
    }
};