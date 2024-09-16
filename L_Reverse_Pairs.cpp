class Solution {
public:
    int ans = 0;
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // ans work:
        int l = low;
        int r = mid + 1;
        while(l <= mid && r <= high) {
            if(nums[l] > 2 * 1LL * nums[r]) {
                ans += mid - l + 1;
                r++;
            }
            else l++;
        }

        // merge work:
        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low; i<=high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if(low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return ans;
    }
};