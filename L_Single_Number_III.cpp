class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // using sort: nlogn time and const space
        // sort(nums.begin(), nums.end()); vector<int> ans;
        // for(int i=0; i<nums.size(); i+=2) {
        //     if(i != nums.size()-1 && nums[i] != nums[i + 1]) {
        //         ans.push_back(nums[i]);
        //         i--; // to increase only one
        //     }
        //     else if(i == nums.size()-1) ans.push_back(nums[i]);
        // }
        // if(ans.size() < 2) ans.push_back(nums[nums.size()-1]);
        // return ans;



        // using hashmap: n time  and n space
        // unordered_map<int, int> mp;
        // for(auto i: nums) mp[i]++;

        // vector<int> ans;
        // for(auto i: mp) {
        //     if(i.second == 1) ans.push_back(i.first);
        // }
        // return ans;




        // using bit manipulation: n time and const space
        int group1 = 0;
        int group2 = 0;

        // finding xorr value of elements of nums:
        int xorr = 0;
        for(auto i: nums) xorr = xorr ^ i;

        // finding first set bit index of xorr ans from nums:
        // set bit in xorr is becoz of conflict bit at an index in both of our ans elements:
        int count = 0;
        while((xorr & 1) != 1)
        {
            xorr = xorr >> 1;
            count++;
        }

        // checking count index of each element in nums and dividing them into two groups:
        // one group containing index bit as 1 and other as 0:
        // both group will contain odd elements with one element in both as our answers:
        for(auto i: nums)
        {
            int element = i;
            element = element >> count;
            if((element & 1) == 0) group1 ^= i;
            else group2 ^= i;
        }

        return {group1, group2};
    }
};