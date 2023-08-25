class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int mini = INT_MAX;

        while( i <= j && j < nums.size() )
        {
            sum += nums[j];

            if(sum >= target)
            {
                mini = min(mini, j-i+1);
                sum -= nums[i];
                sum -= nums[j];
                i++;
            }

            else j++;
        }

        if(mini == INT_MAX) return 0;
        else return mini;
    }
};

