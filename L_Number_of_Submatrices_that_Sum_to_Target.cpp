class Solution {
public:
    int findSum(vector<vector<int>>& matrix, int rows, int rowe, int cols, int cole) {
        int sum = 0;
        for(int row=rows; row<=rowe; row++) {
            for(int col=cols; col<=cole; col++) {
                sum += matrix[row][col];
            }
        }

        return sum;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Approach 1st -> using brute force: Find sum for each submatrices: O(n^3 * m^3)
        int ans = 0;
        for(int rowStart=0; rowStart<n; rowStart++) {
            for(int rowEnd=rowStart; rowEnd<n; rowEnd++) {
                for(int colStart=0; colStart<m; colStart++) {
                    for(int colEnd=colStart; colEnd<m; colEnd++) {
                        int sum = findSum(matrix, rowStart, rowEnd, colStart, colEnd);
                        cout << sum << endl;
                        if(sum == target) ans++;
                    }
                }
            }
        }

        return ans;



        // Approach 2 -> using prefix sum of rows: O(m * m * n);
        calculating prefix sum for each row:
        for(int row=0; row<n; row++) {
            for(int col=1; col<m; col++) matrix[row][col] += matrix[row][col - 1];
        }

        trying all 
        int ans = 0;
        for(int c1=0; c1<m; c1++) {
            for(int c2=c1; c2<m; c2++) {
                unordered_map<int, int> mp; mp[0]++;
                int sum = 0;
                for(int row=0; row<n; row++) {
                    sum += (matrix[row][c2] - (c1 - 1 >= 0 ? matrix[row][c1 - 1] : 0));
                    ans += mp[sum - target];
                    mp[sum]++;
                }
            }
        }

        return ans;
    }
};