class Solution {
public:
    int mod = 1000000007;
    int solve(int index, int seats, string& c, vector<vector<int>>& dp)
    {
        if(index == c.size()) return seats == 2;

        if(dp[index][seats] != -1) return dp[index][seats];

        int ans = 0;
        if(seats < 2)
        {
            int seatP = 0;
            int seatA = 0;
            if(c[index] == 'S') seatP = solve(index + 1, seats + 1, c, dp);
            else seatA = solve(index + 1, seats, c, dp);
            ans += seatP + seatA;
        }
        else
        {
            if(c[index] == 'S') ans += solve(index + 1, 1, c, dp);
            else
            {
                int take = solve(index + 1, seats, c, dp);
                int notTake = solve(index + 1, 0, c, dp);
                ans += take + notTake;
            }
        }

        return dp[index][seats] = ans % mod;
    }

    int solve2(string& c)
    {
        vector<vector<int>> dp (c.size() + 1, vector<int> (3, 0));

        // base case handle:
        dp[c.size()][2] = 1;

        for(int index = c.size()-1; index>=0; index--)
        {
            for(int seats=2; seats>=0; seats--)
            {
                int ans = 0;
                if(seats < 2)
                {
                    int seatP = 0;
                    int seatA = 0;
                    if(c[index] == 'S') seatP = dp[index + 1][seats + 1];
                    else seatA = dp[index + 1][seats];
                    ans += seatP + seatA;
                }
                else
                {
                    if(c[index] == 'S') ans += dp[index + 1][1];
                    else
                    {
                        int take = dp[index + 1][seats];
                        int notTake = dp[index + 1][0];
                        ans += take + notTake;
                    }
                }

                dp[index][seats] = ans % mod;
            }
        }

        return dp[0][0];
    }

    int numberOfWays(string corridor) {
        // dp:
        // vector<vector<int>> dp (corridor.size() + 1, vector<int> (3, -1));
        // return solve(0, 0, corridor, dp);

        // tabulation:
        return solve2(corridor);


        // int seats = 0;
        // for(auto i: corridor)
        // {
        //     if(i == 'S') seats++;
        // }
        // if(seats % 2 != 0 || seats == 0) return 0;
        // if(seats == 2) return 1;

        // int ans = 1;
        // int count = 0;
        // int pots = 0;
        // for(int i=0; i<corridor.size(); i++)
        // {
        //     if(corridor[i] == 'S' && count < 2) count++;
        //     else if(corridor[i] == 'S' && count == 2)
        //     {
        //         count = 1;
        //         ans = ans * 1LL * (pots + 1) % mod;
        //         pots = 0;
        //     }
        //     else if(corridor[i] == 'P' && count == 2) pots++;
        // }
        // return ans;
    }
};