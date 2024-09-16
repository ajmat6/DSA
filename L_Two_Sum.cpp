class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force:
        // for(int i=0; i<nums.size(); i++) {
        //     for(int j=i+1; j<nums.size(); j++) {
        //         if(nums[i]  + nums[j] == target) return {i, j};
        //     }
        // }
        // return {-1, -1};




        // using hashMap: n time and n space:
        // unordered_map<int, int> mp;
        // for(int i=0; i<nums.size(); i++) {
        //     int rem = target - nums[i];
        //     if(mp.find(rem) != mp.end()) return {mp[rem], i};
        //     else mp[nums[i]] = i;
        // }
        // return {-1, -1};



        // using two pionters: not optimal for this question as you have to use another temp vector for storing the pairs of value and index:
        int n = nums.size();
        vector<pair<int, int>> temp;
        for(int i=0; i<n; i++) {
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());
        int low = 0;
        int high = n - 1;

        while(low < high) {
            int firstt = temp[low].first;
            int secondd = temp[high].first;
            if(firstt + secondd == target) return {temp[low].second, temp[high].second};
            else if(firstt + secondd > target) high--;
            else low++;
        }
        return {-1, -1};
    }
};