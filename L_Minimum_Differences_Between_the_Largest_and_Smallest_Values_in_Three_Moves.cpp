class Solution {
public:
    int minDifference(vector<int>& nums) {
        // // using sort: nlogn
        // if(nums.size() <= 4) return 0;
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // int first = nums[n-1] - nums[3]; // first three removed
        // int second = nums[n-2] - nums[2];  // first two and last removed
        // int third = nums[n-3] - nums[1]; // first one and last two removed
        // int fourth = nums[n-4] - nums[0]; // last three removed

        // return min(first, min(second, min(third, fourth)));

        // only first four and last four elements needed:
        if(nums.size() <= 4) return 0;
        priority_queue<int> maxi;
        priority_queue<int, vector<int>, greater<int>> mini;
        for(auto i: nums) {
            maxi.push(i);
            mini.push(i);
        }

        int first[4] = {};
        int last[4] = {};
        for(int i=0; i<4; i++) {
            first[i] = mini.top();
            last[4-i-1] = maxi.top();
            mini.pop(); maxi.pop();
        }

        int ans = INT_MAX;
        for(int i=0; i<4; i++) ans = min(ans, last[i] - first[i]);
        return ans;
    }
};