class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rows (n, 0), cols (m, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] && (rows[i] > 1 || cols[j] > 1)) ans++;
            }
        }
        return ans;
    }
};