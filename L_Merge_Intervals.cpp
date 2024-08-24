class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(auto i: intervals) {
            int size = ans.size();
            if(size == 0 || i[0] > ans[size-1][1]) ans.push_back(i);
            else ans[size-1][1] = max(ans[size-1][1], i[1]);
        }
        return ans;
    }
};