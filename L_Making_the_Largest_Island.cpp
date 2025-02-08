class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

    void bfs(vector<vector<int>>& grid, vector<pair<int, int>>& zeros, unordered_map<int, int>& idSize, int& currId, int i, int j) {
        int count = 1;
        int n = grid.size();
        grid[i][j] = currId;

        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int newRow = currRow + dx[i];
                int newCol = currCol + dy[i];
                if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                    count++;
                    grid[newRow][newCol] = currId;
                    q.push({newRow, newCol});
                }
            }
        }

        idSize[currId++] = count;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> zeros;
        unordered_map<int, int> idSize;

        int currId = 2;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) bfs(grid, zeros, idSize, currId, i, j);
                else if(grid[i][j] == 0) zeros.push_back({i, j});
            }
        }

        if(zeros.size() == 0) return n * n;
        if(zeros.size() == n * n) return 1;

        int ans = 1;
        for(int i=0; i<zeros.size(); i++) {
            int row = zeros[i].first;
            int col = zeros[i].second;

            int currSum = 1;
            vector<int> sides (4, -1);
            for(int j=0; j<4; j++) {
                int newRow = row + dx[j];
                int newCol = col + dy[j];
                if(isValid(newRow, newCol, n) && grid[newRow][newCol] != 0) {
                    int id = grid[newRow][newCol];
                    if(sides[0] != id && sides[1] != id && sides[2] != id && sides[3] != id) {
                        currSum += idSize[grid[newRow][newCol]];
                        sides[j] = id;
                    }
                }
            }
            ans = max(ans, currSum);
        }
        return ans;
    }
};








// using union find:
class DisjointSet {
    public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i=0; i<(n+1); i++) parent[i] = i;
    }

    int ultParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = ultParent(parent[node]);
    }

    void Union(int u, int v) {
        int prtU = ultParent(u);
        int prtV = ultParent(v);

        if(prtU == prtV) return;

        int prtUSize = size[prtU];
        int prtVSize = size[prtV];

        if(prtUSize > prtVSize) {
            size[prtU] += size[prtV];
            parent[prtV] = prtU;
        }
        else {
            size[prtV] += size[prtU];
            parent[prtU] = prtV;
        }
    }
};

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalCells = n * n;
        DisjointSet ds (totalCells);
        vector<pair<int, int>> zeros;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    int firstCellNo = i * n + j;
                    for(int k=0; k<4; k++) {
                        int newRow = i + dx[k];
                        int newCol = j + dy[k];
                        if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                            int secondCellNo = newRow * n + newCol;
                            ds.Union(firstCellNo, secondCellNo);
                        }
                    }
                }
                else zeros.push_back({i, j});
            }
        }

        if(zeros.size() == 0) return n * n;
        if(zeros.size() == n * n) return 1;

        int ans = 1;
        for(int i=0; i<zeros.size(); i++) {
            int row = zeros[i].first;
            int col = zeros[i].second;

            unordered_set<int> prts;
            for(int j=0; j<4; j++) {
                int newRow = row + dx[j];
                int newCol = col + dy[j];
                if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                    int cellNo = newRow * n + newCol;
                    int currUltParent = ds.ultParent(cellNo);
                    prts.insert(currUltParent);
                }
            }
            
            int currSize = 1;
            for(auto &i: prts) {
                currSize += ds.size[i];
            }
            ans = max(ans, currSize);
        }
        return ans;
    }
};