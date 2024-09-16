class Solution {
public:
    bool findCurrPlusOne(vector<int>& nums, int no) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == no) return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        // brute force: n^3 time complexity and constant space:
        // int n = nums.size();
        // int ans = 0;
        // for(int i=0; i<n; i++) {
        //     int curr = nums[i];
        //     int len = 1;
        //     while(findCurrPlusOne(nums, curr + 1)) {
        //         curr += 1;
        //         len += 1;
        //     }
        //     ans = max(ans, len);
        // }
        // return ans;



        // nlogn time and constant space:
        // int n = nums.size();
        // sort(nums.begin(), nums.end());

        // int ans = 0; 
        // int count = 0;
        // int prev = INT_MIN;
        // for(int i=0; i<n; i++) {
        //     if(nums[i] == prev + 1) {
        //         count += 1;
        //         prev = nums[i];
        //     }
        //     else if(nums[i] == prev) continue;
        //     else {
        //         count = 1;
        //         prev = nums[i];
        //     }
        //     ans = max(ans, count);
        // }

        // return ans;




        // using set: n time and n space:
        // insert into the set and for each set element if curr - 1 do exist (means curr cannot be starting point for lcs), then move, otherwise look for curr + 1
        // unordered_set<int> st;
        // for(auto i: nums) st.insert(i);

        // int ans = 0;
        // for(auto i: st) {
        //     if(st.find(i - 1) == st.end()) {
        //         int curr = i;
        //         int count = 1;
        //         while(st.find(curr + 1) != st.end()) {
        //             count += 1;
        //             curr += 1;
        //         }
        //         ans = max(ans, count);
        //     }
        // }
        // return ans;




        // same as unordered_set: n time and n space:
        unordered_map<int, int> mp;
        for(auto i: nums) mp[i]++;

        int ans = 0;
        for(auto i: mp) {
            if(mp.find(i.first - 1) == mp.end()) {
                int curr = i.first;
                int count = 1;
                while(mp.find(curr + 1) != mp.end()) {
                    count += 1;
                    curr += 1;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};