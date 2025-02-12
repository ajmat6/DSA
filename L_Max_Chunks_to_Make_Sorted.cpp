class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size(), maxSeen = -1;
        for(int i=0; i<n; i++) {
            maxSeen = max(maxSeen, arr[i]);
            if(maxSeen == i) ans++;
        }
        return ans;
    }
};