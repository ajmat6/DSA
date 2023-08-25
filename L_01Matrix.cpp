class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> isVisited (n, vector<int> (m, 0));

        // copy and distance matrix:
        vector<vector<int>> mat2 = mat;
        vector<vector<int>> dist (n, vector<int> (m, 0));

        // pushing all zeros into the queue with dist as zero:
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    isVisited[i][j] = true;
                }
            }
        }

        // BFS:
        while(!q.empty())
        {
            // extracting data from front q element:
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            // check for all four direction from current position:
            for(int posRow=-1; posRow<=1; posRow++)
            {
                for(int posCol=-1; posCol<=1; posCol++)
                {
                    if(abs(posRow) + abs(posCol) == 2) continue;

                    int nextRow = row + posRow;
                    int nextCol = col + posCol;

                    if(nextRow >=0 && nextRow <  n && nextCol >=0 && nextCol < m && !isVisited[nextRow][nextCol])
                    {
                        // if 1 is found, then mark it as true 
                        q.push({{nextRow, nextCol}, distance+1});
                        isVisited[nextRow][nextCol] = true;
                        dist[nextRow][nextCol] = distance+1;
                    }
                }
            }
        }

        return dist;
    }
};