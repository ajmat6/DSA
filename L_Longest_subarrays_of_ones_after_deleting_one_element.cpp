class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int leftIndex = 0;
        int rightIndex = 0;
        int zeros = 0;
        int ans = 0;

        for(rightIndex=0; rightIndex<nums.size(); rightIndex++)
        {
            if(nums[rightIndex] == 0) zeros++;

            while(zeros > 1)
            {
                // increase left till leftIndex reach the first zero in the range:
                if(nums[leftIndex] == 0) zeros--;
                
                leftIndex++;
            }

            ans = max(ans, rightIndex - leftIndex - zeros + 1);
        }

        if(ans == nums.size()) return ans - 1;  // if all were ones in the array
        else return ans;
    }
};