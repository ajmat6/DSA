class Solution {
public:
    bool check(int quan, vector<int>& q, int& n) {
        int count = 0;
        for(auto &i: q) count += ((i + quan - 1) / quan);
        if(count <= n) return true;
        return false;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        int ans = 0;
        int low = 1;
        int high = *max_element(q.begin(), q.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(mid, q, n)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};