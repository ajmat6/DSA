class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        // Using prefix and suffix sum:


        // vector<int> left (nums.size());
        // vector<int> right (nums.size());

        // left[0] = nums[0];
        // right[nums.size()-1] = nums[nums.size()-1];
        // for(int i=1; i<nums.size(); i++)
        // {
        //     left[i] = left[i-1] + nums[i];
        // }

        // for(int i=nums.size()-2; i>=0; i--)
        // {
        //     right[i] = right[i+1] + nums[i];
        // }

        // for(int i=0; i<nums.size(); i++)
        // {
        //     if(i == 0)
        //     {
        //         if(right[i+1] == 0) return i;
        //     }

        //     else if(i == nums.size()-1)
        //     {
        //         if(left[i-1] == 0) return i;
        //     }

        //     else if(left[i-1] == right[i+1]) return i;
        // }

        // return -1;

        // using total sum:

        int totalSum = 0;
        for(auto i: nums) totalSum += i;

        int leftSum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int rightSum = totalSum - leftSum - nums[i];
            if(leftSum == rightSum) return i;
            leftSum += nums[i];
        }

        return -1;
    }
};