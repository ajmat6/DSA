class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        if(index == -1) {
            reverse(nums.begin(), nums.end()); 
            return;
        }

        // find next strictly greater element than nums[index];
        int nextGreater = INT_MAX;
        int greaterIndex = -1;
        for(int i=n-1; i>index; i--) {
            if(nums[i] > nums[index]) {
                // as from last till index the array was like 3, 2, 1  -> in decreasing order. So the first element that we will find greater than nums[index] is the next greater. Now you need to reverse it and done!
                swap(nums[index], nums[i]);
                reverse(nums.begin() + index + 1, nums.end()); 
                break;
            } 
        }

        return;
    }
};