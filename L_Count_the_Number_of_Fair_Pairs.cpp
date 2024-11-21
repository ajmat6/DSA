// using sorting and binary search: 3nlogn time
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long ans = 0;
        for(int i=0; i<n; i++) {
            int first = lower - nums[i];
            int second = upper - nums[i];
            int index1 = lower_bound(nums.begin() + i + 1, nums.end(), first) - nums.begin();
            int index2 = upper_bound(nums.begin() + i + 1, nums.end(), second) - nums.begin();
            ans += (index2 - index1);
        }
        return ans;
    }
};




// using two pointers: nlogn + 2n time
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0, high = n - 1;
        long long count = 0;
        while(low < high) {
            if(nums[low] + nums[high] > upper) high--;
            else {
                count += (high - low);
                low++;
            }
        }

        // now remove count of pairs whose sum is less than lower above:
        low = 0, high = n - 1;
        while(low < high) {
            if(nums[low] + nums[high] >= lower) high--;
            else {
                count -= (high - low);
                low++;
            }
        }
        return count;
    }
};