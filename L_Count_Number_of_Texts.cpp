class Solution {
public:
    // mapping of values:
    vector<int> mp = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
    int mod = 1000000007;

    int solve(string& keys, int index, vector<int>& dp)
    {
        if(index == keys.size()) return 1;

        if(dp[index] != -1) return dp[index];

        int ans = 0;
        int key = keys[index] - '0';
        int keySize = mp[key];

        int j = index;
        int count = 0;
        while(keys[j] - '0' == key && count < keySize && j < keys.size())
        {
            ans = (ans % mod + solve(keys, j+1, dp) % mod) % mod;
            j++;
            count++;
        }

        dp[index] = ans;

        return ans;
    }

    // Tabulation:
    int solve2(string& keys)
    {
        int n = keys.size();
        vector<int> dp (n+1, 0);
        dp[n] = 1;

        for(int index=n-1; index>=0; index--)
        {
            int ans = 0;
            int key = keys[index] - '0';
            int keySize = mp[key];

            int j = index;
            int count = 0;
            while(keys[j] - '0' == key && count < keySize && j < keys.size())
            {
                ans = (ans % mod + dp[j+1] % mod) % mod;
                j++;
                count++;
            }

            dp[index] = ans;
        }


        return dp[0];
    }

    int countTexts(string pressedKeys) {
        // Memorisation:
        // vector<int> dp (pressedKeys.size(), -1);
        // return solve(pressedKeys, 0, dp);

        // Tabulation:
        return solve2(pressedKeys);
    }
};