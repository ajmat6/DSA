class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long long sum = 0;
        int i = 0;

        while(sum < n)
        {
            if(i < nums.size() && nums[i] <= sum + 1)
            {
                sum += nums[i];
                i++;
            }
            else
            {
                sum = 2 * sum + 1;
                ans++;
            }
        }

        return ans;
    }
};