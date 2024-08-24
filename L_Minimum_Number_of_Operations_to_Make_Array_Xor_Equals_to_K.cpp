class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // find xor:
        int xorr = 0;
        for(auto i: nums) xorr ^= i;

        int ans = 0;
        for(int i=0; i<32; i++) {
            int first = xorr & 1;
            int second = k & 1;
            if(first != second) ans += 1;
            xorr >>= 1;
            k >>= 1;
        }
        return ans;
    }
};