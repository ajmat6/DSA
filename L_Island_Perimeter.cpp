class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int row=0; row<grid.size(); row++) {
            for(int col=0; col<grid[0].size(); col++) {
                if(grid[row][col] == 1) {
                    for(int i=0; i<4; i++) {
                        int newRow = row + dx[i];
                        int newCol = col + dy[i];
                        if(newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size()) ans++;
                        else if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 0) ans++;
                    }
                }
            }
        }

        return ans;
    }
};