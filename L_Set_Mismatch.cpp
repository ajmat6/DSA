class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // Approach 1st -> brute force: TC is O(n*n) and SC is O(1)
        // int repeat, miss;
        // for(int i=1; i<=nums.size(); i++) {
        //     bool found = false;
        //     int count = 0;
        //     for(int j=0; j<nums.size(); j++) {
        //         if(nums[j] == i) {
        //             found = true; count++;
        //         }
        //     }

        //     if(!found) miss = i;
        //     if(count == 2) repeat = i;
        // }

        // return {repeat, miss};


        // Approach 2nd -> using sort: TC is O(nlogn) and SC is O(n)
        // int repeat;
        // vector<int> isPresent (nums.size() + 1, 0);
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // for(int i=0; i<n - 1; i++) {
        //     if(nums[i] == nums[i + 1]) {
        //         repeat = nums[i];
        //     }
        //     isPresent[nums[i]] = 1;
        // }
        // isPresent[nums[n - 1]] = 1;
        // for(int i=1; i<nums.size() + 1; i++) {
        //     if(!isPresent[i]) return {repeat, i};
        // }

        // return {0, 0};

        // Approach 3rd -> using unordered map: TC is O(n) and SC is O(n)
        // unordered_map<int, int> mp;
        // for(auto i: nums) mp[i]++;
        // int repeat, miss;
        // for(int i=1; i<=nums.size(); i++) {
        //     if(mp[i] == 2) repeat = i;
        //     if(mp[i] == 0) miss = i;
        // }
        // return {repeat, miss};

        // Approach 4th: using set and sum: TC is O(n) and SC is O(n)
        // int n = nums.size();
        // int total = (n * (n + 1))/ 2;
        // set<int> st;
        // int repeat;
        // for(auto i: nums) {
        //     if(st.find(i) != st.end()) repeat = i;
        //     st.insert(i);
        // }
        // int sum = 0;
        // for(auto i: st) sum += i;
        // return {repeat, total - sum};

        // Approach 5th -> using xor: TC is O(n) and SC is O(1);
        // if you can find the repeating no, then on xoring all elements with 1 based indexing, you will be left with repeating ^ missing no. Therefor again xoring with the repeating no will give missing no
        int repeat, miss;
        miss = 0;
        for(int i=0; i<nums.size(); i++) {
            miss = miss ^ (i + 1) ^ abs(nums[i]); 
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0) repeat = abs(nums[i]);
            else nums[index] *= -1;
        }

        return {repeat, miss ^ repeat};
    }
};