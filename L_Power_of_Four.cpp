class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n == 1) return true;

        // while(n >= 4)
        // {
        //     int rem = n % 4;
        //     if(rem != 0) return false;

        //     // on keep dividing with 4, you will get 4 at end, means true, but for it you must check that reminder should be zero previously as on dividing 17 with 4, n will become 4 but it is not a power of 4:
        //     if(n == 4) return true;
        //     else
        //     {
        //         n = n / 4;
        //     }
        // }

        // return false;

        return n > 0 && (n & (n-1)) == 0 && (n & (0x55555555));
    }
};