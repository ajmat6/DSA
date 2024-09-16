class Solution {
public:
    bool check(vector<int>& start, int d, int diff) {
        long long prevTaken = start[0];
        for(int i=1; i<start.size(); i++) {
            long long nextToTake = max(prevTaken + diff, (long long)start[i]);
            if(nextToTake > start[i] + d) return false;
            prevTaken = nextToTake;
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        // do binary search over the answer:
        int ans = 0;
        int low = 0;
        sort(start.begin(), start.end());
        int high = start[start.size() - 1] + d - start[0]; // highest possible answer:
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(start, d, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }

        return ans;
    }
};