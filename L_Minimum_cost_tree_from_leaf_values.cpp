class Solution {
public:
    // Recursion: Gives TLE
    int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right)
    {
        // Base case:
        if(left == right) return 0;

        int ans = INT_MAX;
        for(int i=left; i<right; i++)
        {
            // storing ans for all types of structures possible:
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i+1, right));
        }

        return ans;
    }

    int solve2(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int>>& dp)
    {
        // Base case:
        if(left == right) return 0;

        // checking for dp:
        if(dp[left][right] != -1) return dp[left][right];

        int ans = INT_MAX;
        for(int i=left; i<right; i++)
        {
            // storing ans for all types of structures possible:
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solve2(arr, maxi, left, i, dp) + solve2(arr, maxi, i+1, right, dp));
        }

        // storing in dp:
        dp[left][right] = ans;

        return dp[left][right];
    }

    // Tabulation:
    int solve3(vector<int>& arr, map<pair<int, int>, int>& maxi)
    {
        int n = arr.size();

        // Create 2d vector:
        vector<vector<int>> dp (n+1, vector<int> (n+1, 0));

        for(int left=n-1; left>=0; left--)
        {
            for(int right=left+1; right<n; right++)
            {
                int ans = INT_MAX;
                for(int i=left; i<right; i++)
                {
                    // storing ans for all types of structures possible:
                    ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
                }
                dp[left][right] = ans;
            }
        }

        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        // for storing max value in a range:
        map<pair<int, int>, int> maxi;
        
        for(int i=0; i<arr.size(); i++)
        {
            maxi[{i, i}] = arr[i]; // same element is greatest at its own position:
            for(int j=i+1; j<arr.size(); j++)
            {
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        // Recursion:
        // return solve(arr, maxi, 0, arr.size()-1);

        // Memorisation:
        // int n = arr.size();
        // vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        // return solve2(arr, maxi, 0, n-1, dp);

        return solve3(arr, maxi);
    }
};