class Solution {
public:
    long long minEnd(int n, int x) {
        long long one = 1, ans = x, currBitPos = 0;
        for(int i=0; i<64; i++) {
            if((x & (one << i)) == 0) {
                if(n - 1 & (one << currBitPos)) ans ^= (one << i);
                currBitPos++;
            }
        }
        return ans;
    }
};  