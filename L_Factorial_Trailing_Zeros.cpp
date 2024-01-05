class Solution {
public:
    int trailingZeroes(int n) {
        // solved using the intution that we have to count no of twos and five's in the factorial multiplication of a number:
        // number of 5's are always less than no of 2's:
        // so we have to count no of 5 as prime factors of a number:
        // we can see that every five no from 0 have 5 as its prime factors:
        // we can count no of 5 as a numbers prime factors and include in our answer:

        if(n < 5) return 0;

        // int no = 0;
        // int ans = 0;
        // while(no + 5 <= n)
        // {
        //     int count = 0;
        //     no += 5;
        //     int temp = no;
        //     while(temp % 5 == 0)
        //     {
        //         count++;
        //         temp = temp / 5;
        //     }
            
        //     ans += count;
        // }

        // return ans;

        int ans = 0;
        for(int i=5; i<=n; i*=5)
        {
            ans += n / i;
        }

        return ans;
    }
};