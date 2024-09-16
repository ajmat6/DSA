class Solution {
public:
    bool check(vector<int>& stalls, int k, int dist) {
        int currCows = 1;
        int nextStall = stalls[0] + dist;
        
        for(int i=1; i<stalls.size(); i++) {
            if(stalls[i] >= nextStall) {
                currCows++;
                nextStall = stalls[i] + dist;
                if(currCows == k) return true;
            }
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            // check wheather this mid gap is possible gap b/w cows:
            if(check(stalls, k, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};