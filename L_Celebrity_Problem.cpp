class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int low = 0;
        int high = n - 1;
        
        while(low < high) {
            if(mat[low][high]) low++;
            else high--;
        }
        
        // check low row -> it should be 0 and low col -> it should be 1 except low index:
        for(int i=0; i<n; i++) {
            if(mat[low][i] == 1) return -1;
            if(i != low && mat[i][low] != 1) return -1;
        }
        
        return low;
    }
};