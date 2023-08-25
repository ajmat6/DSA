class Solution {
public:
    bool Prime(int n)
    {
        while(n != 1)
        {
            if(n % 2 == 0)
            {
                n = n / 2;
                continue;
            }

            else if(n % 3 == 0)
            {
                n = n / 3;
                continue;
            }

            else if(n % 5 == 0)
            {
                n = n / 5;
                continue;
            }

            else break;
        }

        if(n == 1) return true;
        else return false;
    }

    int solve(int n, int uglyCount, int currNo)
    {
        if(uglyCount == n) return currNo-1;

        int total = 0;
        if(Prime(currNo))
        {
            total = solve(n, uglyCount+1, currNo+1);
        }

        else 
        {
            total = solve(n, uglyCount, currNo+1);
        }

        return total;
    }

    

    int nthUglyNumber(int n) {
        // Using sets:
        // set<long long> track;
        // long long nthUgly = 1;

        // track.insert(nthUgly);

        // for(int i=0; i<n; i++)
        // {
        //     nthUgly = *track.begin();

        //     // add 2, 3 and 5th multipliers of curr nthUgly as they will also be ugly nos:
        //     track.insert(nthUgly*2);
        //     track.insert(nthUgly*3);
        //     track.insert(nthUgly*5);

        //     // now erase currUgly no from set as we are tracing for min no in the set:
        //     track.erase(nthUgly);
        // }

        // return nthUgly;

        vector<int> dp (n);
        dp[0] = 1;

        int two = 0;
        int three = 0;
        int five = 0;

        for(int i=1; i<n; i++)
        {
            dp[i] = min(dp[two]*2, min(dp[three]*3, dp[five]*5));

            if(dp[i] == dp[two] * 2) two++;
            if(dp[i] == dp[three] * 3) three++;
            if(dp[i] == dp[five] * 5) five++;
        }

        return dp[n-1];

        // Using dp:
        // int uglyCount = 1;
        // return solve(n, uglyCount, 2);

    }
};