class Solution {
  public:
    bool checkForMid(vector<int>& arr1, vector<int>& arr2, int k, int mid) {
        int count = 0;
        count += upper_bound(arr1.begin(), arr1.end(), mid) - arr1.begin();
        count += upper_bound(arr2.begin(), arr2.end(), mid) - arr2.begin();
        if(count >= k) return true;
        return false;
    }
    
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int low = min(arr1[0], arr2[0]);
        int high = max(arr1[n - 1], arr2[m - 1]);
        
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(checkForMid(arr1, arr2, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};