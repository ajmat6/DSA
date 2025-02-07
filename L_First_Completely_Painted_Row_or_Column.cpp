class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int size = n * m;

        vector<int> rows(n, m), cols(m, n);
        vector<int> valueRow(size + 1), valueCol(size + 1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                valueRow[mat[i][j]] = i;
                valueCol[mat[i][j]] = j;
            }
        }

        for(int i=0; i<size; i++) {
            int value = arr[i];
            int currRow = valueRow[value];
            int currCol = valueCol[value];
            if(--rows[currRow] == 0 || --cols[currCol] == 0) return i;
        }

        return 0;
    }
};