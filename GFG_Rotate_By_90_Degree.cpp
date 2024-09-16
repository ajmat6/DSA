class Solution
{   
    public:
    void rotateby90(vector<vector<int> >& arr, int n) 
    { 
        for(int row=0; row<n; row++) {
            for(int col=row; col<n-1-row; col++) {
                int first = arr[n - 1 - col][row];
                arr[n - 1 - col][row] = arr[row][col];
                int second = arr[n - 1 - row][n - 1 - col];
                arr[n - 1 - row][n - 1 - col] = first;
                int third = arr[col][n - 1 - row];
                arr[col][n - 1 - row] = second;
                arr[row][col] = third;
            }
        }
    } 
};