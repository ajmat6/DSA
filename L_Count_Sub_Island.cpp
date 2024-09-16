class Disjoint {
    vector<int> size;
    vector<int> parent;

    public:

    Disjoint(int n) {
        size.resize(n + 1);
        parent.resize(n + 1);

        for(int i=0; i<=n; i++) {
            size[i] =  1;
            parent[i] = i;
        }
    }

    int ultimateParent(int u) {
        if(parent[u] == u) return u;
        else parent[u] = ultimateParent(parent[u]);
    }

    void union(int u, int v) {
        int uPrt = ultimateParent(u);
        int vPrt = ultimateParent(v);

        if(uPrt == vPrt) return; // pehle se he union

        if(size[uPrt] >= size[vPrt]) {
            parent[vPrt] = uPrt;
            size[uPrt] += size[vPrt];
        }

        else {
            parent[uPrt] = vPrt;
            size[vPrt] += size[uPrt];
        }
    }
};

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // dfs:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col, bool& poss) {
        if(grid1[row][col] == 0) poss = false;
        grid2[row][col] = 0; // for not visiting same land cell again

        for(int i=0; i<4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if(newRow >= 0 && newRow < grid1.size() && newCol >= 0 && newCol < grid1[0].size() && grid2[newRow][newCol] == 1) dfs(grid1, grid2, newRow, newCol, poss);
        }
    }

    // bfs:
    void bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col, bool& poss, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while(!q.empty()) {
            auto cell = q.front(); q.pop();
            int currRow = cell.first;
            int currCol = cell.second;

            if(grid1[currRow][currCol] == 0) poss = false;
            for(int i=0; i<4; i++) {
                int newRow = currRow + dx[i];
                int newCol = currCol + dy[i];
                if(newRow >= 0 && newRow < grid1.size() && newCol >= 0 && newCol < grid1[0].size() && grid2[newRow][newCol] == 1 && vis[newRow][newCol] == 0) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // using dfs:
        // int m = grid1.size();
        // int n = grid1[0].size();

        // int ans = 0;
        // for(int i=0; i<m; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(grid2[i][j] == 1) {
        //             bool poss = true;
        //             dfs(grid1, grid2, i, j, poss);
        //             if(poss) ans += 1;
        //         }
        //     }
        // }

        // return ans;


        // using bfs:
        // int m = grid1.size();
        // int n = grid1[0].size();

        // int ans = 0;
        // vector<vector<int>> vis (m, vector<int> (n, 0));
        // for(int i=0; i<m; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(grid2[i][j] == 1 && !vis[i][j]) {
        //             bool poss = true;
        //             bfs(grid1, grid2, i, j, poss, vis);
        //             if(poss) ans += 1;
        //         }
        //     }
        // }
        // return ans;
    }
};