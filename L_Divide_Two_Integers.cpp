class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long ans = 0;

        // when dividend and divisor both are of same sign, no need of negative sign in ans:
        int isSign = ((dividend < 0) ^ (divisor < 0)) == 0 ? 1 : -1;

        while(dvd >= dvs)
        {
            long long tempDvs = dvs;
            long long times = 1;

            // doubling divisor at each step and checking if it is lesser than dividend:
            while(tempDvs << 1 <= dvd)
            {
                tempDvs <<= 1;
                times <<= 1;
            }

            // subtracting already calculated ans divisor from dividend:
            dvd -= tempDvs;
            ans += times;
        }

        return ans * isSign; // negative ans case
    }
};