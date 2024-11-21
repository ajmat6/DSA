class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int ans = 0;

        int countFresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) q.push({i, j}); // pushing all rotten oranges into the queue
                if(grid[i][j] == 1) countFresh++;
            }
        }

        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int j=0; j<4; j++) {
                    int newRow = row + dx[j];
                    int newCol = col + dy[j];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1) {
                        countFresh--;
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                    }
                }
            }

            if(!q.empty()) ans += 1; 
        }

        return countFresh == 0 ? ans : -1;
    }
};