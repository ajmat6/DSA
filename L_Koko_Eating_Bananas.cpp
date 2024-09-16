class Solution {
public:
    bool check(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for(auto i: piles) {
            hours += i / k;
            if(i % k != 0) hours += 1;
        }
        if(hours <= h) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};