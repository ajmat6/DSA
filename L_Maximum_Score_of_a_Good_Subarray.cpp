class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        // two pointers:

        int i = k;
        int j = k;
        int diff = 1; // to track j - i + 1

        int ans = INT_MIN;
        int mini = nums[i];
        while(i >= 0 && j < nums.size())
        {
            ans = max(ans, mini * diff);

            if(j != nums.size()-1 && i != 0)
            {
                if(nums[j + 1] >= nums[i-1])
                {
                    j++;
                    mini = min(mini, nums[j]);
                }

                else
                {
                    i--;
                    mini = min(mini, nums[i]);
                }

                diff++;
            }

            else if(j == nums.size()-1 && i != 0)
            {
                i--;
                mini = min(mini, nums[i]);
                diff++;
            }

            else if(j != nums.size()-1 && i == 0)
            {
                j++;
                mini = min(mini, nums[j]);
                diff++;
            }

            else break;
        }

        return ans;
    }
};