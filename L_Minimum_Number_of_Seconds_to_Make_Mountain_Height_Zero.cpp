class Solution {
public:
    bool check(int mh, vector<int>& wt, long long val) {
        long long count = 0;
        for(auto i: wt) {
            long long curr = i;
            long long time = 0;
            while(true) {
                if(time + curr <= val) {
                    count++;
                    if(count >= mh) return true;
                    time += curr;
                    curr += i;
                }
                else break;
            }
        }

        if(count >= mh) return true;
        return false;
    }

    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long low = 1;
        long long high = LONG_MAX;

        long long ans = 0;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            cout << mid << endl;
            if(check(mh, wt, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};