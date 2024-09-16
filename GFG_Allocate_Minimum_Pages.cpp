class Solution {
  public:
    bool check(int arr[], int n, int m, int pages) {
        int count = 1;
        int currPages = 0;
        for(int i=0; i<n; i++) {
            currPages += arr[i];
            if(currPages > pages) {
                count += 1;
                currPages = arr[i];
            }
        }
        if(count <= m) return true;
        return false;
    }
    
    long long findPages(int n, int arr[], int m) {
        if(n < m) return -1;
        
        int totalSum = 0;
        int maxPages = 0;
        for(int i=0; i<n; i++) {
            totalSum += arr[i];
            maxPages = max(maxPages, arr[i]);
        }
        
        int ans = 0;
        int low = maxPages;
        int high = totalSum;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(arr, n, m, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};