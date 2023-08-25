class Solution {
public:
                        // Dijkstra Algorithm:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        
        // no nedd to store priority queue as for every step our distance increases by 1:
        queue<pair<int, pair<int, int>>>q; // <distance, <row, col>>
        vector<vector<int>> dist (n, vector<int> (m, 0));

        // initializing distance vector with infinity:
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                dist[i][j] = INT_MAX;
            }
        }

        // initializing source with zero:
        dist[0][0] = 0;

        // pusing source node into the queue:
        q.push({0, {0, 0}});

        while(!q.empty())
        {
            auto min = q.front();
            q.pop();

            int row = min.second.first;
            int col = min.second.second;
            int distance = min.first;

            if(row == n-1 && col == m-1) return distance + 1;

            // check for all the possible directions:
            for(int possRow=-1; possRow<=1; possRow++)
            {
                for(int possCol=-1; possCol<=1; possCol++)
                {
                    int nextRow = row + possRow;
                    int nextCol = col + possCol;

                    if(nextRow >=0 && nextRow < n && nextCol >= 0 && nextCol < m && grid[nextRow][nextCol] == 0 && distance + 1 < dist[nextRow][nextCol])
                    {
                        // update distance:
                        dist[nextRow][nextCol] = 1 + distance;

                        // pushing into the queue:
                        q.push({dist[nextRow][nextCol], {nextRow, nextCol}});
                    }
                }
            }
        }

        return -1;
    }
};