class Solution {
public:
    // double solve(double x, int n)
    // {
    //     // Base case:
    //     if(n == INT_MAX) return (x == 1)? 1 : (x == -1)? -1 : 0;
    //     if(n == INT_MIN) return (x == 1)? 1 : (x == -1)?  1 : 0;
    //     if(n == 0) return 1;

    //     if(n < 0) return 1 / x * solve(x, n+1);
    //     else return x * solve(x, n-1);
    // }

    double solve(double x, int n)
    {
        if(n == 0) return 1;
        if(n < 0)
        {
            n = abs(n);
            x = 1 / x;
        }

        if(n % 2 == 0) return solve(x*x, n/2);
        else return x * solve(x, n-1);
    }

    double myPow(double x, int n) {
        // double ans = 1;
        // int limit = abs(n);
        // for(int i=0; i<limit; i++)
        // {
        //     if(n < 0)
        //     {
        //         ans = ans * 1 / x;
        //     }

        //     else 
        //     {
        //         ans = ans * x;
        //     }
        // }
        // return ans;

        return solve(x, n);
    }
};