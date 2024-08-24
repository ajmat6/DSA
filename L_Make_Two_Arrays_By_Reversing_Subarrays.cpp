class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // using map:
        // unordered_map<int, int> mp1;
        // unordered_map<int, int> mp2;
        // for(auto i: target) mp1[i]++;
        // for(auto i: arr) mp2[i]++;
        // for(auto i: target) {
        //     if(mp1[i] != mp2[i]) return false;
        // }
        // return true;

        // using sort:
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};