class Solution {
public:
    long long maximumTotalSum(vector<int>& mh) {
        sort(mh.begin(), mh.end(), greater<int>());
        long long ans = mh[0];
        int prev = ans;
        for(int i=1; i<mh.size(); i++) {
            if(prev - 1 == 0) return -1;
            else if(mh[i] >= prev - 1) {
                ans += (prev - 1);
                prev -= 1;
            }
            else {
                ans += mh[i];
                prev = mh[i];
            }
        }
        return ans;
    }
};