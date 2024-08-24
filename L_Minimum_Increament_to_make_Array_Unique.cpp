class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // counting sort: n time and space
        // int maxi = INT_MIN;
        // for(auto i: nums) maxi = max(maxi, i);
        // vector<int> temp (maxi + 1);
        // for(auto i: nums) temp[i]++;
        // for(int i=1; i<temp.size(); i++) temp[i] += temp[i - 1];
        // vector<int> sorted(nums.size());
        // for(int i=nums.size()-1; i>=0; i--) {
        //     int pos = temp[nums[i]] - 1;
        //     sorted[pos] = nums[i];
        //     temp[nums[i]]--;
        // }

        // // question logic
        // int start = sorted[0]; int ans = 0;
        // for(int i=1; i<sorted.size(); i++) {
        //     if(sorted[i] <= start) {
        //         ans += (start + 1 - sorted[i]);
        //         start += 1;
        //     } 
        //     else start = sorted[i];
        // }
        // return ans;

        // using hashmap: nlogn time and n space
        map<int, int> mp;
        for(auto i: nums) mp[i]++;

        int ans = 0;
        for(auto i = mp.begin(); i != mp.end(); i++) {
            if(i -> second > 1) {
                ans += i -> second - 1;
                mp[i -> first + 1] += i -> second - 1;
            }
        }
        return ans;
    }
};