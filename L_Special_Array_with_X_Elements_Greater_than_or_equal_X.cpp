class Solution {
public:
    int specialArray(vector<int>& nums) {
        // n^2 solution:
        // sort(nums.begin(), nums.end());
        // for(int i=1; i<=nums.size(); i++) {
        //     int count = 0;
        //     for(int j=0; j<nums.size(); j++) {
        //         if(nums[j] >= i) count++;
        //     }
        //     if(count == i) return i;
        // }
        // return -1;



        // using binary search: n * logn:
        sort(nums.begin(), nums.end());
        for(int i=1; i<=nums.size(); i++) {
            int count = nums.size() - (lower_bound(nums.begin(), nums.end(), i) - nums.begin());
            if(count == i) return i;
        }
        return -1;


        // using binary search: n * logn:
        sort(nums.begin(), nums.end(), greater<int>());
        if(nums[0] == 0) return -1;
        if(nums[0])
    }
};