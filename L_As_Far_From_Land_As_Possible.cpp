class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis (n, vector<int> (n, 0));
        queue<pair<int, pair<int, int>>> q;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        int ans = INT_MAX;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            int cost = front.first;
            int row = front.second.first;
            int col = front.second.second;

            cout << row << " " << col << endl;

            int dx[4] = {0, -1, 0, 1};
	        int dy[4] = {-1, 0, 1, 0};
	       
	        ans = cost;

            for(int i=0; i<4; i++)
	        {
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !vis[newRow][newCol])
                {
                    q.push({cost + 1, {newRow, newCol}});
                    vis[newRow][newCol] = 1;
                }
	        }
        }

        if(ans == INT_MAX || ans == 0) return -1;
        return ans;
    }
};