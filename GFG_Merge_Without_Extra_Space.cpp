class Solution{
    public:
        void swapElements(long long arr1[], long long arr2[], int pos1, int pos2) {
            swap(arr1[pos1], arr2[pos2]);
            return;
        }
        
        void merge(long long arr1[], long long arr2[], int n, int m) { 
            // using striver method 1: constant space and min(n, m) + nlogn + mlogm time:
            // int left = n - 1;
            // int right = 0;
            
            // while(left >= 0 && right < m) {
            //     if(arr1[left] > arr2[right]) {
            //         swap(arr1[left], arr2[right]);
            //         left--;
            //         right++;
            //     }
            //     else break;
            // }
            
            // sort(arr1, arr1 + n);
            // sort(arr2, arr2 + m);
            
            
            
            
            // using striver method 2: Gap method: log(n + m) * (n + m) time and constant space
            int totalSize = n + m;
            int ceilGap = (totalSize / 2) + (totalSize % 2);
            
            while(true) {
                int low = 0;
                int high = low + ceilGap;
                
                while(high < totalSize) {
                    // when low is in first half and high is in second half:
                    if(low < n && high >= n) {
                        if(arr1[low] > arr2[high - n]) {
                            swapElements(arr1, arr2, low, high - n);
                        }
                    }
                    
                    // when both low and high are in second half(array):
                    else if(low >= n) {
                        if(arr2[low - n] > arr2[high - n]) {
                            swapElements(arr2, arr2, low - n, high - n);
                        }
                    }
                    
                    // both are in first half:
                    else {
                        if(arr1[low] > arr1[high]) {
                            swapElements(arr1, arr1, low, high);
                        }
                    }
                    
                    low++;
                    high++;
                }
                
                if(ceilGap == 1) break;
                ceilGap =  ceilGap / 2 + ceilGap % 2;
            }
            
        } 
};