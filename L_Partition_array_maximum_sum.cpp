class Solution {
public:
    int recursion(vector<int>& arr, int k, int index)
    {
        int n = arr.size();

        // Base Case:
        if(index == n) return 0;

        // len is to track the length of our subarray formed:
        int len = 0;

        // maxInSize is track the max element in our subarray formed:
        int maxInSize = INT_MIN;
        int ans = INT_MIN;


        // as we can we have maximum subarray of size k:
        for(int i=index; i < min(n, index+k); i++)
        {
            len++;
            maxInSize = max(maxInSize, arr[i]);

            int partition = len * maxInSize + recursion(arr, k, i+1);
            ans = max(ans, partition);
        }

        return ans;
    }

    int memo(vector<int>& arr, int k, int index, vector<int>& dp)
    {
        int n = arr.size();

        // Base Case:
        if(index == n) return 0;

        // check for dp:
        if(dp[index] != -1) return dp[index];

        int len = 0;
        int maxInSize = INT_MIN;
        int ans = INT_MIN;

        for(int i=index; i < min(n, index+k); i++)
        {
            len++;
            maxInSize = max(maxInSize, arr[i]);

            int partition = len * maxInSize + memo(arr, k, i+1, dp);
            ans = max(ans, partition);
        }

        // Storing in dp:
        dp[index] = ans;

        return ans;
    }

    int tab(vector<int>& arr, int k)
    {
        int n = arr.size();
        vector<int> dp (n+1, 0);

        for(int index=n-1; index>=0; index--)
        {
            int len = 0;
            int maxInSize = INT_MIN;
            int ans = INT_MIN;

            for(int i=index; i < min(n, index+k); i++)
            {
                len++;
                maxInSize = max(maxInSize, arr[i]);

                int partition = len * maxInSize + dp[i+1];
                ans = max(ans, partition);
            }

            // Storing in dp:
            dp[index] = ans;
        }

        return dp[0];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // return recursion(arr, k, 0);

        // Memorisation:
        // int n = arr.size();
        // vector<int> dp (n, -1);
        // return memo(arr, k, 0, dp);

        // Tabulation:
        return tab(arr, k);
    }
};