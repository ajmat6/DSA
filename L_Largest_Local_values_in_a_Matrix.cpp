class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans (grid.size()-2, vector<int> (grid[0].size()-2));
        int row = 0; int col = 0;
        for(int i=0; i<grid.size()-2; i++) {
            for(int j=0; j<grid[0].size()-2; j++) {
                for(int k=i; k<=i+2; k++) {
                    for(int l=j; l<=j+2; l++) {
                        ans[row][col] = max(ans[row][col], grid[k][l]);
                    }
                }
                col++;
            }
            row++;
            col = 0;
        }
        return ans;
    }
};