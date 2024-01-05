class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int ans = INT_MAX;
        int low = 0;
        int high = 0;
        long long sum = 0;

        // finding sum of all elements:
        long long allSum = 0;
        for(auto i: nums) allSum += i;

        int count = target / allSum;
        int rem = target % allSum;

        int n = nums.size();

        if(rem == 0) return count * n;
        else target = rem;
    
        while(high < 2 * n)
        {
            sum += nums[high % n];
            
            while(sum > target && low < n)
            {
                sum -= nums[low % n];
                low++;
            }

            if(sum == target)
            {
                ans = min(ans, high - low + 1);
            }

            high++;
        }

        return ans == INT_MAX ? -1 : ans + n * count;
    }
};