class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        long long ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > maxi) maxi = nums[i];
        }
        
        int low = 0;
        int high = 0;
        int count = 0;

        while(high < nums.size())
        {
            if(nums[high] == maxi) count++;
            
            while(count >= k)
            {
                ans += (nums.size() - high);
                if(nums[low] == maxi) count--;
                low++;
            }

            high++;
        }        
        
        return ans;
    }
};