class DisjointSet {
    vector<int> size;
    vector<int> parent;

    public:
    DisjointSet(int n) {
        size.resize(n);
        parent.resize(n);

        for(int i=0; i<n; i++) {
            size[i] = 1;
            parent[i] = i;
        } 
    }

    int ultprt(int node) {
        if(parent[node] == node) return node;
        else return parent[node] = ultprt(parent[node]);
    }

    bool unionn(int u, int v) {
        int uprt = ultprt(u);
        int vprt = ultprt(v);

        if(uprt == vprt) return true;

        int uSize = size[uprt];
        int vSize = size[vprt];

        if(uSize >= vSize) {
            parent[vprt] = uprt;
            size[uprt] += size[vprt];
        }

        else {
            parent[uprt] = vprt;
            size[vprt] += size[uprt];
        }

        return false;
    }
};

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& vis, int row, int col) {
        vis[row][col] = 1;
        for(int i=0; i<4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if(newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix.size() && vis[newRow][newCol] == 0 && matrix[newRow][newCol] == 0) {
                dfs(matrix, vis, newRow, newCol);
            }
        }
        return;
    }

    int regionsBySlashes(vector<string>& grid) {
        // int n = grid.size();
        // int N = n + 1;
        // int totalPoints = N * N;

        // DisjointSet ds(totalPoints);
        
        // // first make union of boundary points:
        // for(int i=0; i<N; i++) {
        //     for(int j=0; j<N; j++) {
        //         if(i == 0 || i == n || j == 0 || j == n) {
        //             int pointNumber = i * N + j;
        //             ds.unionn(0, pointNumber);
        //         }
        //     }
        // }

        // // now iterate over the grid and make union of the lines:
        // int ans = 0;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(grid[i][j] == '/') {
        //             int point1 = (i + 1) * N + j;
        //             int point2 = i * N + (j + 1);
        //             if(ds.unionn(point1, point2)) ans++;
        //         }
        //         else if(grid[i][j] == '\\') {
        //             int point1 = i * N + j;
        //             int point2 = (i + 1) * N + (j + 1);
        //             if(ds.unionn(point1, point2)) ans++;
        //         }
        //     }
        // }
        // return ans + 1;

        int n = grid.size();
        vector<vector<int>> matrix (n * 3, vector<int> (n * 3, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '/') {
                    int row = 3 * i; int col = 3 * j + 2; int end = row + 3;
                    while(row != end) {
                        matrix[row][col] = 1;
                        row++;
                        col--;
                    }
                }
                else if(grid[i][j] == '\\') {
                    int row = 3 * i; int col = 3 * j; int end = row + 3;
                    while(row != end) {
                        matrix[row][col] = 1;
                        row++;
                        col++;
                    }
                }
            }
        }

        int ans = 0;
        vector<vector<int>> vis (n * 3, vector<int> (n * 3, 0));
        for(int i=0; i<n*3; i++) {
            for(int j=0; j<n*3; j++) {
                if(vis[i][j] == 0 && matrix[i][j] == 0) {
                    dfs(matrix, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};s