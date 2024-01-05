class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // unordered_map<int, pair<int, int>> rowList;
        // unordered_map<int, pair<int, int>> colList;

        // int n = grid.size();
        // int m = grid[0].size();

        // for(int i=0; i<n; i++)
        // {
        //     int oneCount = 0;
        //     int zeroCount = 0;
        //     for(int j=0; j<m; j++)
        //     {
        //         if(grid[i][j] == 1) oneCount++;
        //         else zeroCount++;
        //     }

        //     rowList[i] = {zeroCount, oneCount};
        // }

        // for(int i=0; i<m; i++)
        // {
        //     int oneCount = 0;
        //     int zeroCount = 0;
        //     for(int j=0; j<n; j++)
        //     {
        //         if(grid[j][i] == 1) oneCount++;
        //         else zeroCount++;
        //     }

        //     colList[i] = {zeroCount, oneCount};
        // }

        // // building ans:
        // vector<vector<int>> ans (n, vector<int> (m));
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         ans[i][j] = rowList[i].second + colList[j].second - rowList[i].first - colList[j].first;
        //     }
        // }

        // return ans;


        // second approach: TC is O(m * n) and SC is O(m + n)
        // these arrays will store no of ones in each row and col respectively:
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rowList (n);
        vector<int> colList (m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                rowList[i] += grid[i][j];
                colList[j] += grid[i][j];
            }
        }

        // building ans:
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                grid[i][j] = rowList[i] + colList[j] - (m - rowList[i]) - (n - colList[j]);
            }
        }

        return grid;
    }
};