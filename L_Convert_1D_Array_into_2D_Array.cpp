class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m * n != original.size()) return {};
        vector<vector<int>> ans;
        
        for(int i=0; i<m; i++) {
            ans.push_back(vector<int> (original.begin() + (i * n), original.begin() + (i + 1) * n));
        }
        return ans;
    }
};