class Solution {
public:
    bool checkForMid(vector<int>& arr1, vector<int>& arr2, int mid, bool evenCheck) {
        int count = 0;
        int n = arr1.size();
        int m = arr2.size();
        count += upper_bound(arr1.begin(), arr1.end(), mid) - arr1.begin();
        count += upper_bound(arr2.begin(), arr2.end(), mid) - arr2.begin();
        if(!evenCheck && count > (n + m) / 2) return true;
        else if(evenCheck && count >= (n + m) / 2) return true;
        return false;
    }

    int binarySearch(vector<int>& arr1, vector<int>& arr2, int low, int high, bool evenCheck) {
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(checkForMid(arr1, arr2, mid, evenCheck)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        // int n = arr1.size();
        // int m = arr2.size();
        // int low = 0;
        // int high = 0;

        // if(n == 0) {
        //     low = arr2[0];
        //     high = arr2[m - 1];
        // }
        // else if(m == 0) {
        //     low = arr1[0];
        //     high = arr1[n - 1];
        // }
        // else {
        //     low = min(arr1[0], arr2[0]);
        //     high = max(arr1[n - 1], arr2[m - 1]);
        // }
        
        // int ans = binarySearch(arr1, arr2, low, high, false);
        // if((n + m) % 2 == 1) return ans;
        // int prev = binarySearch(arr1, arr2, low, high, true);
        // return (ans + prev) * 1.0 / 2;



        // strivers approach:
        int n = arr1.size();
        int m = arr2.size();

        if(n > m) return findMedianSortedArrays(arr2, arr1);

        int low = 0;
        int high = n;
        int totalLeft = (m + n + 1) / 2;
        while(low <= high) {
            int mid1 = low + (high - low) / 2; // no of elements from smaller array;
            int mid2 = totalLeft - mid1; // from larger array
            
            // you will pick mid elements from arr1 and rest from arr2:
            int l1 = INT_MIN; int r1 = INT_MAX;
            int l2 = INT_MIN; int r2 = INT_MAX;

            if(mid1 > 0) l1 = arr1[mid1 - 1];
            if(mid2 > 0) l2 = arr2[mid2 - 1];
            if(mid1 < n) r1 = arr1[mid1];
            if(mid2 < m) r2 = arr2[mid2];

            if(l1 <= r2 && l2 <= r1) {
                if((m + n) % 2 == 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }

        return 0;
    }
};