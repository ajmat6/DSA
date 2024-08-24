class Solution {
public:
    bool checkUniquePlusRowSum(vector<vector<int>>& grid, int i, int j) {
        set<int> st;
        for(int k=i; k<=i+2; k++) {
            int sum = 0;
            for(int l=j; l<=j+2; l++) {
                sum += grid[k][l];
                if(st.find(grid[k][l]) != st.end() || grid[k][l] > 9) return false;
                else st.insert(grid[k][l]);
            }
            if(sum != 15) return false;
        }
        return true;
    }

    bool checkColumnSum(vector<vector<int>>& grid, int i, int j) {
        for(int k=j; k<=j+2; k++) {
            int sum = 0;
            for(int l=i; l<=i+2; l++) sum += grid[l][k];
            if(sum != 15) return false;
        }
        return true;
    }

    bool checkDiagonalSum(vector<vector<int>>& grid, int i, int j) {
        if(grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] == 15 && grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] == 15) return true;
        return false;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n < 3 || m < 3) return 0;

        int ans = 0;
        for(int i=0; i<n-2; i++) {
            for(int j=0; j<m-2; j++) {
                bool unique = checkUniquePlusRowSum(grid, i, j);
                bool colSum = checkColumnSum(grid, i, j);
                bool diagonalSum = checkDiagonalSum(grid, i, j);
                if(unique && colSum && diagonalSum) ans++;
            }
        }
        return ans;
    }
};