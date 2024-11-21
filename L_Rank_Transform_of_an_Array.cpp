class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // if(arr.size() == 0) return {};
        // using map: slower -> nlogn time and n space:
        // vector<int> nums = arr;
        // map<int, int> mp;
        // sort(nums.begin(), nums.end());
        // mp[nums[0]] = 1;
        // for(int i=1; i<arr.size(); i++) {
        //     if(nums[i] > nums[i - 1]) mp[nums[i]] = mp[nums[i - 1]] + 1;
        // }
        // vector<int> ans;
        // for(auto i: arr) ans.push_back(mp[i]);
        // return ans;



        // using pair of value and index: n time and n space:
        vector<pair<int, int>> nums;
        for(int i=0; i<arr.size(); i++) nums.push_back({arr[i], i});

        sort(nums.begin(), nums.end());
        vector<int> ans (arr.size());
        int currRank = 0;
        int prevElem = INT_MIN;
        for(auto& [value, index]: nums) {
            if(value > prevElem) currRank++;
            ans[index] = currRank;
            prevElem = value;
        }
        return ans;
    }
};