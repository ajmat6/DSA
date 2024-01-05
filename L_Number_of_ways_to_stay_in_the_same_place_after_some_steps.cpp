class Solution {
public:
    int mod = 1000000007;
    int solve(int steps, int arrLen, int index, int count, vector<vector<int>>& dp)
    {
        if(count == steps)
        {
            if(index == 0) return 1;
            else return 0;
        }

        if(dp[index][count] != -1) return dp[index][count];

        // stay at same place:
        int stay = solve(steps, arrLen, index, count + 1, dp) % mod;
        int right = 0;
        int left = 0;
        if(index + 1 != min(steps, arrLen)) right = solve(steps, arrLen, index + 1, count + 1, dp) % mod;
        if(index - 1 != -1) left = solve(steps, arrLen, index - 1, count + 1, dp) % mod;

        int total = (stay * 1LL + right * 1LL + left * 1LL) % mod;
        return dp[index][count] = total;
    }

    int solve2(int steps, int arrLen)
    {
        int sizee = min(steps, arrLen);
        vector<vector<int>> dp (steps + 1, vector<int> (sizee + 1, 0));

        // base case handle:
        dp[steps][0] = 1;

        for(int count=steps-1; count>=0; count--)
        {
            for(int index=sizee-1; index>=0; index--)
            {
                int stay = dp[count + 1][index] % mod;
                int right = 0;
                int left = 0;
                if(index < sizee-1) right = dp[count + 1][index + 1] % mod;
                if(index > 0) left = dp[count + 1][index - 1] % mod;
                int total = ((stay + right) % mod + left) % mod;
                dp[count][index] = total;
            }
        }

        return dp[0][0];
    }

    int solve3(int steps, int arrLen)
    {
        int sizee = min(steps, arrLen);
        vector<int> curr (sizee + 1, 0);
        vector<int> next (sizee + 1, 0);

        next[0] = 1;

        for(int count=steps-1; count>=0; count--)
        {
            for(int index=sizee-1; index>=0; index--)
            {
                int stay = next[index] % mod;
                int right = 0;
                int left = 0;
                if(index < sizee-1) right = next[index + 1] % mod;
                if(index > 0) left = next[index - 1] % mod;
                int total = ((stay + right) % mod + left) % mod;
                curr[index] = total;
            }

            next = curr;
        }

        return curr[0];
    }

    int numWays(int steps, int arrLen) {
        // maximum time a person can move right to end at index 0 at last is steps / 2. But in problem arrLen can be smaller than steps / 2 . so we are taking min of steps and arrLen:

        // recursion + Memorisation:
        // int sizee = min(steps, arrLen);
        // vector<vector<int>> dp (sizee + 1, vector<int> (steps + 1, -1));
        // return solve(steps, arrLen, 0, 0, dp);

        // Tabulation:
        return solve2(steps, arrLen);

        // Space Optimisation:
        return solve3(steps, arrLen);
    }
};