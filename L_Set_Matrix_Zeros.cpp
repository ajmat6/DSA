class Solution {
public:
    void makeAllZeros(vector<vector<int>>& matrix, int row, int col)
    {
        // make row zero:
        for(int i=0; i<matrix[0].size(); i++)
        {
            matrix[row][i] = 0;
        }

        // make col zero:
        for(int i=0; i<matrix.size(); i++)
        {
            matrix[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // vector<pair<int, int>> temp;

        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         if(matrix[i][j] == 0) temp.push_back({i, j});
        //     }
        // }

        // // make all zeros:
        // for(auto i: temp)
        // {
        //     int row = i.first;
        //     int col = i.second;

        //     makeAllZeros(matrix, row, col);
        // }

        // approach 2:

        // setting zeros row to -9999
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k=0; k<m; k++)
                    {
                        if(matrix[i][k] != 0)
                        {
                            matrix[i][k] = -9999;
                        }
                    }
                }
            }
        }

        // setting column of zero to -9999:
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k=0; k<n; k++)
                    {
                        if(matrix[k][j] != 0)
                        {
                            matrix[k][j] = -9999;
                        }
                    }
                }
            }
        }

        // setting all -9999 to 0:
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == -9999)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};