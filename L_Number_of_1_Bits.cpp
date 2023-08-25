class Solution {
public:
    int hammingWeight(uint32_t n) {
        // int ans = 0;
        // while(n)
        // {
        //     if(n & 1 == 1) ans++;
        //     n = n >> 1;
        // }
        // return ans;

        // solution 2:
        int ans = 0;
        while(n)
        {
            if(n % 2) ans++;
            n = n >> 1;
        }
        return ans;
    }
};