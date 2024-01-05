class Solution {
public:
    int mod = 1000000007;
    int solve(int n, int pos, unordered_map<int, list<int>>& mp, vector<vector<int>>& dp)
    {
        if(n == 0) return 1;

        if(dp[n][pos] != -1) return dp[n][pos];

        int ans = 0;
        for(auto& i: mp[pos])
        {
            int temp = solve(n - 1, i, mp, dp);
            ans = (ans % mod + temp) % mod;
        }

        return dp[n][pos] = ans;
    }

    

    int knightDialer(int n) {
        // if(n == 1) return 10;

        unordered_map<int, list<int>> mp;
        mp[0] = {4, 6};
        mp[1] = {6, 8};
        mp[2] = {7, 9};
        mp[3] = {4, 8};
        mp[4] = {3, 9, 0};
        mp[5] = {};
        mp[6] = {0, 1, 7};
        mp[7] = {2, 6};
        mp[8] = {1, 3};
        mp[9] = {2, 4};

        // vector<vector<int>> dp (n + 1, vector<int> (10, -1));

        // int ans = 0;
        // for(int i=0; i<=9; i++)
        // {
        //     int temp = solve(n - 1, i, mp, dp);
        //     ans = (ans % mod + temp) % mod;
        // }

        // return ans;

        vector<int> curr (10, 1);
        for(int i=2; i<=n; i++)
        {
            vector<int> temp (10);
            for(int j=0; j<10; j++)
            {
                for(auto i: mp[j])
                {
                    temp[j] = (temp[j] + curr[i] ) % mod;
                }
            }
            curr = temp;
        }

        int ans = 0;
        for(auto i: curr)
        {
            ans = (ans + i) % mod;
        }
        return ans;
    }
};