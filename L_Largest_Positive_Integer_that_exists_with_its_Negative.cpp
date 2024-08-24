class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // using map:
        // unordered_map<int, int> mp;
        // for(auto i: nums) mp[i]++;
        // int ans = -1;
        // for(auto i: nums) {
        //     if(i > 0 && mp.find(-i) != mp.end() && i > ans) ans = i;  
        // }
        // return ans;


        // using sort:
        // sort(nums.begin(), nums.end());
        // for(int i=nums.size()-1; i>=0; i--) {
        //     if(nums[i] > 0 && binary_search(nums.begin(), nums.end(), -nums[i]) != 0) return nums[i];
        // }
        // return -1;

        // using sort and two pointers:
        // sort(nums.begin(), nums.end());
        // int low = 0, right = nums.size() - 1;
        // while(low < right && nums[low] < 0 && nums[right] > 0) {
        //     if(abs(nums[low]) == nums[right]) return nums[right];
        //     else if(abs(nums[low]) < nums[right]) right--;
        //     else low++;
        // }
        // return -1;

        // using seen array: best solution
        int seen[1001] = {0}; int ans = -1;
        for(auto i: nums) {
            if(i < 0) seen[abs(i)] |= 2; // or is done instead of addition to avoid 2 + 2 = 4 and it will never catch = 3, while bitwise or gives duplicate number addition as same number
            else seen[i] |= 1;
            if(seen[abs(i)] == 3 && abs(i) > ans) ans = abs(i);
        }
        return ans;
    }
};