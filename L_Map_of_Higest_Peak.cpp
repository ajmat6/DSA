class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        queue<pair<int, int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(isWater[i][j] == 1) 
                {
                    isWater[i][j] = 0;
                    q.push({i, j});
                }
                else isWater[i][j] = -1;
            }
        }

        // biparatite graph:

        while(!q.empty())
        {
            auto front = q.front(); q.pop();
            int row = front.first;
            int col = front.second;
            int type = isWater[row][col];

            for(int i=0; i<4; i++)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && isWater[newRow][newCol] == -1)
                {
                    int newType = type + 1; // to make sure maximum height (bfs property that it will reach a cell in the minimum shortest distance from the source cell and there will be no such situation when the absolute diff will be greater than 2)

                    isWater[newRow][newCol] = newType;
                    q.push({newRow, newCol});
                }
            }
        }

        return isWater;
    }
};