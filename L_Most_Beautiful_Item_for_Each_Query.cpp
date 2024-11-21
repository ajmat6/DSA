class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        
        int maxi = items[0][1];
        for(int i=1; i<n; i++) {
            maxi = max(maxi, items[i][1]);
            items[i][1] = maxi;
        }

        vector<int> ans;
        for(auto &i: queries) {
            int index = (upper_bound(items.begin(), items.end(), vector<int> {i, INT_MAX}) - items.begin()) - 1;
            if(index >= 0) ans.push_back(items[index][1]);
            else ans.push_back(0);
        }
        return ans;
    }
};