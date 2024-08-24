class Solution {
public:
    bool check(vector<int> bloomDay, int m, int k, int days) { // takes O(n) time:
        int count = 0;
        for(auto i: bloomDay) {
            if(i <= days) {
                count++;
                if(count == k) {
                    m--;
                    if(m == 0) return true;
                    else count = 0;
                }
            }
            else count = 0;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m * 1LL * k > bloomDay.size()) return - 1;
        int minDays = INT_MAX; int maxDays = INT_MIN;
        for(auto i: bloomDay) {
            minDays = min(minDays, i);
            maxDays = max(maxDays, i);
        }

        // do binary search b/w min and max days:
        int low = minDays; int high = maxDays; int ans = maxDays;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};