class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // // using hashMap: O(n) time and O(n) space:
        // unordered_map<int, int> mp;
        // for(auto i: nums) mp[i]++;
        // for(auto i: mp) {
        //     if(i.second > nums.size() / 2) return i.first;
        // }
        // return 0;




        // // using sort: nlogn time and constant space:
        // sort(nums.begin(), nums.end());
        // int index = 0;
        // while(index < nums.size()) {
        //     int prev = index;
        //     while(index < nums.size() && nums[index] == nums[prev]) index++;
        //     if((index - prev) > nums.size() / 2) return nums[prev];
        // }
        // return 0;




        // // using bit manipulation: 31 * n time and const space:
        // int ans = 0;
        // for(int i=0; i<=31; i++) {
        //     int mask = 1 << i;
        //     int count = 0;
        //     for(int j=0; j<nums.size(); j++) {
        //         if(nums[j] & mask) count++;
        //     }

        //     if(count > nums.size() / 2) ans |= mask;
        // }
        // return ans;




        // // using boyer moore's voting algo: n time and constant space:
        int element = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++) {
            if(count == 0) {
                element = nums[i];
                count++;
            }
            else if(nums[i] == element) count++;
            else count--;
        }
        return element;
    }
};