// using all unique space: can use map also here to optimise space but will effect time:
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<int> freq (1e5 + 1, 0);
        long long sum = 0;
        int low = 0, count = 0;

        int n = nums.size();
        long long ans = 0;
        for(int high=0; high<n; high++) {
            sum += nums[high];
            if(freq[nums[high]] == 1) count++;
            freq[nums[high]]++;

            if(high - low + 1 == k) {
                if(count == 0) ans = max(ans, sum);
                sum -= nums[low];
                if(freq[nums[low]] == 2) count--;
                freq[nums[low]]--;
                low++;              
            }
        }
        return ans;
    }
};


// using k space: 
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> freq;
        int n = nums.size(), low = 0;
        long long sum = 0, ans = 0;

        for(int high=0; high<n; high++) {
            if(freq.find(nums[high]) == freq.end()) {
                sum += nums[high];
                freq.insert(nums[high]);
                if(high - low + 1 == k) {
                    ans = max(ans, sum);
                    sum -= nums[low];
                    freq.erase(nums[low]);
                    low++;
                }
            }
            else {
                while(nums[low] != nums[high]) {
                    sum -= nums[low];
                    freq.erase(nums[low]);
                    low++;
                }
                low++;
            }
        }
        return ans;
    }
};