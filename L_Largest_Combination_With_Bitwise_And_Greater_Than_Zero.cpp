class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        vector<int> bits (25);
        int n = candidates.size();
        for(int i=0; i<25; i++) {
            int mask = 1 << i;
            for(int j=0; j<n; j++) {
                if(candidates[j] & mask) bits[i]++;
            }
            ans = max(ans, bits[i]);
        }
        return ans;
    }
};