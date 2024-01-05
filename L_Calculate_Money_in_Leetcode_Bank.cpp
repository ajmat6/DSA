class Solution {
public:
    int totalMoney(int n) {
        // int start = 1;
        // int next = 0;
        // int ans = 0;
        // for(int i=1; i<=n; i++)
        // {
        //     if(i % 7 == 1)
        //     {
        //         next = start;
        //         start++;
        //     }
        //     ans += next;
        //     next++;
        // }
        // return ans;

        int a = 1;
        int d = 1;
        int terms = 7;
        int ans = 0;
        while(n > 0)
        {
            if(n - 7 >= 0) n -= 7;
            else
            {
                terms = n;
                n = 0;
            }
            ans += terms / 2.0 * (2 * a + (terms - 1) * d);
            a++;
        }
        return ans;
    }
};