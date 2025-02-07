class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstSum = 0;
        int n = grid[0].size();
        for(int i=0; i<n; i++) firstSum += grid[0][i];

        long long secondSum = 0;
        long long ans = LLONG_MAX;
        for(int i=0; i<n; i++) {
            firstSum -= grid[0][i];
            ans = min(ans, max(firstSum, secondSum));
            secondSum += grid[1][i];
        }
        return ans;
    }
};