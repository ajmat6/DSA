class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // // brute force: n * m time and constant space:
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         if(matrix[i][j] == target) return true;
        //     }
        // }
        // return false;



        // // better: binary search over each row: n * log(m) time and constant space:
        // for(int i=0; i<n; i++) {
        //     int low = 0;
        //     int high = m - 1;
        //     while(low <= high) {
        //         int mid = low + (high - low) / 2;
        //         if(matrix[i][mid] == target) return true;
        //         else if(matrix[i][mid] > target) high = mid - 1;
        //         else low = mid + 1;
        //     }
        // }
        // return false;




        // Optimal: binary search over the matrix considering it as a linear array: log(m * n) time and constant space:
        int low = 0;
        int high = (n * m) - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};