// using bfs:
class Solution {
public:
    void createAdjList(unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& isVisited, vector<vector<char>>& grid)
    {
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] == 1 && i != j)
                {
                    int u = i;
                    int v = grid[i][j];

                    adjList[u].push_back(v);
                    adjList[v].push_back(u);
                }
            }
        }
    }

    void BFS(vector<vector<bool>>& isVisited, vector<vector<char>>& grid, int row, int column)
    {
        queue<pair<int, int>> q;
        q.push({row, column});
        isVisited[row][column] = true;

        while(!q.empty())
        {
            int frontRow = q.front().first;
            int frontCol = q.front().second;
            q.pop();

            // Traversing current land block in grid and checking them if they are land:
            for(int newRow=-1; newRow<=1; newRow++)
            {
                for(int newCol=-1; newCol<=1; newCol++)
                {
                    // we have to avoid the diagonal block:
                    if(abs(newRow) + abs(newCol) == 2) continue;

                    int pstRow = frontRow + newRow;
                    int pstCol = frontCol +  newCol;

                    if(pstRow >= 0 && pstRow < grid.size() && pstCol >= 0 && pstCol < grid[0].size() && !isVisited[pstRow][pstCol] && grid[pstRow][pstCol] == '1')
                    {
                        isVisited[pstRow][pstCol] = true;
                        q.push({pstRow, pstCol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // 2d vector for tracking visited grids:
        vector<vector<bool>> isVisited (n, vector<bool> (m, false));

        int ans = 0;
        // BFS Traversal:
        for(int row=0; row<n; row++)
        {
            for(int column=0; column<m; column++)
            {
                if(!isVisited[row][column] && grid[row][column] == '1')
                {
                    ans++;
                    BFS(isVisited, grid, row, column);
                }
            }
        }

        return ans;
    }
};




// using dfs:
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        for(int i=0; i<4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == '1' && vis[newRow][newCol] == 0) {
                vis[newRow][newCol] = 1;
                dfs(grid, newRow, newCol, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> vis (rows, vector<int> (cols, 0));
        int ans = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    ans += 1;
                    vis[i][j] = 1;
                    dfs(grid, i, j, vis);
                }
            }
        }

        return ans;
    }
};