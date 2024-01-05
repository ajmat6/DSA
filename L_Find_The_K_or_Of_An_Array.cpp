class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0; i<31; i++)
        {
            int count = 0;
            for(int j=0; j<nums.size(); j++)
            {
                int element = nums[j] >> i;
                if(element & 1) count++;
            }
            
            if(count >= k)
            {
                ans = ans | (1 << i);
            }
            
            // else ans = ans & (1 << i);
        }
        
        return ans;
    }
};