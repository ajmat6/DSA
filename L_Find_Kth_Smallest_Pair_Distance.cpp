class Solution {
public:
    int findNoOfPairs(vector<int>& nums, int& diff) {
        int high = 1;
        int count = 0;
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            if(high <= i) high = i + 1;
            while(high < n && nums[high] - nums[i] <= diff) high++;
            count += high - i - 1;  
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        // find min diff:
        int mini = INT_MAX;
        int n = nums.size();
        for(int i=1; i<n; i++) mini = min(mini, nums[i] - nums[i - 1]);
        int maxi = nums[n - 1] - nums[0];

        // binary search the result from mini to maxi:
        int low = mini;
        int high = maxi;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int noOfPairs = findNoOfPairs(nums, mid);
            if(noOfPairs >= k) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};