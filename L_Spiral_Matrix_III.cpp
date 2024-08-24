class Solution {
public:
    bool check(int& row, int& col, int& n, int& m) {
        if(row >= 0 && row < n && col >= 0 && col < m) return true;
        return false;
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans; ans.push_back({row, col});
        int row = rStart;
        int col = cStart;

        int dir = 0;
        int moves = 1;
        while(ans.size() < rows * cols) {
            for(int i=0; i<moves && ans.size() < rows * cols; i++) {
                if(dir == 0) col++; // right
                else if(dir == 1) row++; // down
                else if(dir == 2) col--; // left;
                else row--; // up

                if(check(row, col, rows, cols)) ans.push_back({row, col});
            }
            if(dir == 1 || dir == 3) moves++;

            if(dir == 0) dir = 1;
            else if(dir == 1) dir = 2;
            else if(dir == 2) dir = 3;
            else dir = 0;
        }

        return ans;
    }
};