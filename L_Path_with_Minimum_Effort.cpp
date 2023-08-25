class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // defining priority queue:
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

        // efforts vector:
        vector<vector<int>> efforts (n, vector<int> (m, 0));

        // initializing efforts vector with infinity:
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                efforts[i][j] = INT_MAX;
            }
        }

        // initializing source effort:
        efforts[0][0] = 0;

        // pushing source node into the queue:
        q.push({0, {0, 0}});
        
        while(!q.empty())
        {
            auto front = q.top();
            q.pop();
            int row = front.second.first;
            int col = front.second.second;
            int diff = front.first;

            // if curr index is final index:
            if(row == n-1 && col == m-1) return diff;

            // check for all the possible directions 8 directions:
            for(int possRow=-1; possRow<=1; possRow++)
            {
                for(int possCol=-1; possCol<=1; possCol++)
                {
                    // ignoring diagonal indexes:
                    if(abs(possRow) + abs(possCol) == 2) continue;

                    int nextRow = row + possRow;
                    int nextCol = col + possCol;


                    // conditions to update the distance of possible next index:
                    if(nextRow >=0 && nextRow < n && nextCol >= 0 && nextCol < m)
                    {
                        // new effort calculation:
                        int newEffort = max(diff, abs(heights[row][col] - heights[nextRow][nextCol]));

                        // check if newEffort is lesser than current effort of the poss index:
                        if(newEffort < efforts[nextRow][nextCol])
                        {
                            efforts[nextRow][nextCol] = newEffort;
                            q.push({newEffort, {nextRow, nextCol}});
                        }
                    }
                }
            }
        }

        return 0; // unreachable only to escape from error
    }
};