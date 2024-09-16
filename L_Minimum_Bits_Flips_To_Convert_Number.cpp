class Solution {
public:
    int minBitFlips(int start, int goal) {
        // checking at each bit position using left shift:
        int ans = 0;
        for(int i=0; i<=31; i++) {
            int mask = 1 << i;
            int first = start & mask;
            int second = goal & mask;
            if(first != second) ans += 1;
        }
        return ans;



        // // using the concept that xorr gives one when there are opposite bits and using brian kerninghans algorithm:
        int xorValue = start ^ goal;
        int ans = 0;
        while(xorValue != 0) {
            xorValue &= (xorValue - 1);
            ans += 1;
        }
        return ans;




        // using the concept that xorr gives one when there are opposite bits and using brian kerninghans algorithm:
        int xorValue = start ^ goal;
        int ans = 0;
        while(xorValue != 0) {
            if(xorValue & 1) ans += 1;
            xorValue >>= 1;
        }
        return ans;
    }
};