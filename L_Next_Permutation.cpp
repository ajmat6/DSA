class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find first dip index from the last:
        int index = -1;
        for(int i=nums.size()-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                index = i;
                break;
            }
        }

        // if no dip is found like in case of 3, 2, 1, then reverse nums and done!
        if(index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // else as we have to  return next lexicographically permutation, find minimun element to be replaced with index element from index + 1 to nums.size():
        
        sort(nums.begin() + index + 1, nums.end()); // sorting to make min no possible after finding index:

        // finding just greater element than index element:
        int minIndex = -1;
        int minGreater = INT_MAX;
        for(int i=index+1; i<nums.size(); i++)
        {
            if(nums[i] > nums[index] && nums[i] < minGreater)
            {
                minIndex = i;
                minGreater = nums[i];
            }
        }

        swap(nums[index], nums[minIndex]);
    }
};