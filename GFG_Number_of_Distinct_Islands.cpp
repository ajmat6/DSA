class Solution {
  public:
    void DFS(int row, int column, vector<pair<int, int>>& v, vector<vector<int>>& grid, vector<vector<int>>& isVisited, int baseRow, int baseCol)
    {
        int n = grid.size();
        int m = grid[0].size();
        v.push_back({row - baseRow, column - baseCol});
        isVisited[row][column] = true;
        
        // check for all possible for four direction:
        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1; j++)
            {
                // skip diagonal move:
                if(abs(i) + abs(j) == 2) continue;

                int newRow = row + i;
                int newCol  = column + j;

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !isVisited[newRow][newCol])
                {
                    DFS(newRow, newCol, v, grid, isVisited, baseRow, baseCol);
                }
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> isVisited (n, vector<int> (m, 0));
        
        // set for storing distinct islands:
        set<vector<pair<int, int>>> s;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                vector<pair<int, int>> v;
                DFS(i, j, v, grid, isVisited, i, j);
                s.insert(v);
            }
        }
        
        return s.size();
    }
};