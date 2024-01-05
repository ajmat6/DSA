class Solution {
public:
    int mod = 1000000007;
    int solve(vector<int>& arr, int index, unordered_map<int, int>& mp, vector<int>& dp)
    {
        if(dp[index] != -1) return dp[index];

        int ans = 1; 
        int node = arr[index];
        for(int i=0; i<=index; i++) // root's child should have lesser value than root for product satisfaction
        {
            if(node % arr[i] == 0) // node is a factor of i.first -> like 20 is factor of 10
            {
                int first = arr[i];
                int remaining = node / first; // for 20 -> if first is 10 then we will search for 2

                if(mp.find(remaining) != mp.end())
                {
                    int rec1 = solve(arr, mp[first], mp, dp);
                    int rec2 = solve(arr, mp[remaining], mp, dp);
                    ans = (ans + (rec1 * 1LL * rec2) % mod) % mod;

                }
            }
        }

        return dp[index] = ans;
    }

    // Tabulation:
    int solve2(vector<int>& arr, unordered_map<int, int>& mp)
    {
        vector<int> dp (arr.size() + 1, 0);

        for(int index = 0; index<arr.size(); index++)
        {
            int ans = 1; 
            int node = arr[index];
            for(int i=0; i<index; i++) // root's child should have lesser value than root for product satisfaction
            {
                if(node % arr[i] == 0) // node is a factor of i.first -> like 20 is factor of 10
                {
                    int first = arr[i];
                    int remaining = node / first; // for 20 -> if first is 10 then we will search for 2
                    if(mp.find(remaining) != mp.end())
                    {
                        int rec1 = dp[mp[first]];
                        int rec2 = dp[mp[remaining]];
                        ans = (ans + (rec1 * 1LL * rec2) % mod) % mod;
                    }
                }
            }
            
            dp[index] = ans;
        }

        long long res = 0;
        for(auto i: dp) res += i;
        return res % mod;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        // create hashmap:
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++) mp[arr[i]] = i;

        // considering each node as root:
        // int ans = 0;
        // vector<int> dp (arr.size() + 1, -1);
        // for(int i=0; i<arr.size(); i++)
        // {
        //     int temp = solve(arr, i, mp, dp);
        //     ans = (ans + temp) % mod;
        // }

        // return ans;

        return solve2(arr, mp) % mod;
    }
};