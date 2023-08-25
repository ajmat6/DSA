class Solution {
public:
    // void DFS(int row, int column, vector<vector<int>>& grid, vector<vector<int>>& grid2, int& ans)
    // {
    //     grid2[row][column] = 2; // changing present row and column block with new colour

    //     for(int newRow=-1; newRow<=1; newRow++)
    //     {
    //         for(int newCol=-1; newCol<=1; newCol++)
    //         {
    //             if(abs(newRow) + abs(newCol) == 2) continue; // diagonal blocks
    //             if(newRow == newCol) continue; // same block

    //             int nowRow = newRow + row;
    //             int nowCol = newCol + column;

    //             // checking condition for further DFS call:
    //             if(nowRow >= 0  && nowRow < grid.size() && nowCol >= 0 && nowCol < grid[0].size() && grid[nowRow][nowCol] == 1 && grid2[nowRow][nowCol] != 2)
    //             {
    //                 // if(ans)
    //                 DFS(nowRow, nowCol, grid, grid2, ans+1);
    //             }
    //         }
    //     }
    // }

    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> grid2 (grid.size(), vector<int> (grid[0].size(), 0));
        queue<pair<pair<int, int>, int>> q;
        int ans = 0;

        // Intializing grid2 for rotten oranges:
        for(int row=0; row<grid.size(); row++)
        {
            for(int column=0; column<grid[0].size(); column++)
            {
                if(grid[row][column] == 2)
                {
                    grid2[row][column] = 2;
                    q.push({{row, column}, 0}); // pushing into the queue for rotten ornages
                }
            }
        }

        while(!q.empty())
        {
            int rotRow = q.front().first.first;
            int rotCol = q.front().first.second;
            int time = q.front().second;
            ans = max(ans, time);
            q.pop();

            for(int newRow=-1; newRow<=1; newRow++)
            {
                for(int newCol=-1; newCol<=1; newCol++)
                {
                    if(abs(newRow) + abs(newCol) == 2) continue; // diagonal blocks
                    if(newRow == newCol) continue; // same block

                    int nowRow = newRow + rotRow;
                    int nowCol = newCol + rotCol;

                    // checking condition for further DFS call:
                    if(nowRow >= 0  && nowRow < grid.size() && nowCol >= 0 && nowCol < grid[0].size() && grid[nowRow][nowCol] == 1 && grid2[nowRow][nowCol] != 2)
                    {
                        grid2[nowRow][nowCol] = 2;
                        q.push({{nowRow, nowCol}, time+1});
                    }
                }
            }
        }

        // check if there is any fresh orange after above process:
        for(int row=0; row<grid.size(); row++)
        {
            for(int column=0; column<grid[0].size(); column++)
            {
                if(grid[row][column] == 1 && grid2[row][column] != 2) return -1;
            }
        }
        return ans;
    }
};