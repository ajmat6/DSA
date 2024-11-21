class Solution {
public:
    static bool cmp(int& a, int& b) {
        string first = to_string(a);
        string second = to_string(b);
        return first + second > second + first;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans = "";
        if(nums[0] == 0) return "0";
        for(auto i: nums) ans += to_string(i);
        return ans;
    }
};