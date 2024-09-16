class Solution{   
public:
    int checkForMedian(vector<vector<int>>& matrix, int n, int m, int val) {
        int smallerEqual = 0;
        for(int i=0; i<n; i++) {
            // binary search over each row to find smaller or equal elements:
            smallerEqual += upper_bound(matrix[i].begin(), matrix[i].end(), val) - matrix[i].begin();
        }
        
        if(smallerEqual > (m * n) / 2) return true;
        return false;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i=0; i<R; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }
        
        
        // binary search over the ans b/w low and high:
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(checkForMedian(matrix, R, C, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return ans;
    }
};
