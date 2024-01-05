class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = LONG_MIN;
        
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size()-1; j++)
            {
                for(int k=j+1; k<nums.size(); k++)
                {
                    long long temp = (nums[i] - nums[j]) * 1LL * nums[k];
                    ans = max(ans, temp);
                }
            }
        }
        
        return ans < 0 ? 0 : ans;
    }
};