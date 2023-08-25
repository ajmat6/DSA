class Solution{
public:
    int solve(int arr[], int i, int j)
    {
        if(i == j) return 0;
        
        // loop for all the possibel partitions:
        int mini = INT_MAX;
        for(int k=i; k<=j-1; k++)
        {
            int steps = arr[i-1] * arr[k] * arr[j] + solve(arr, i, k) + solve(arr, k+1, j);
            mini = min(mini, steps);
        }
        
        return mini;
    }
    
    // Memorisation:
    int solve2(int arr[], int i, int j, vector<vector<int>>& dp)
    {
        if(i == j) return 0;
        
        // check for dp:
        if(dp[i][j] != -1) return dp[i][j];
        
        // loop for all the possibel partitions:
        int mini = INT_MAX;
        for(int k=i; k<=j-1; k++)
        {
            int steps = arr[i-1] * arr[k] * arr[j] + solve2(arr, i, k, dp) + solve2(arr, k+1, j, dp);
            mini = min(mini, steps);
        }
        
        // storing in dp:
        dp[i][j] = mini;
        
        return mini;
    }
    
    // Memorisation:
    int solve3(int arr[], int N)
    {
        vector<vector<int>> dp (N, vector<int> (N, 0));
        
        for(int i=N-1; i>=1; i--)
        {
            // as i is always in left of j:
            for(int j=i+1; j<=N-1; j++)
            {
                // loop for all the possibel partitions:
                int mini = INT_MAX;
                for(int k=i; k<=j-1; k++)
                {
                    int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini, steps);
                }
                
                // storing in dp:
                dp[i][j] = mini;
            }
        }
        
        return dp[1][N-1];
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // return solve(arr, 1, N-1);
        
        // Memorisation:
        // vector<vector<int>> dp (N, vector<int> (N, -1));
        // return solve2(arr, 1, N-1, dp);
        
        // Tabulation:
        return solve3(arr, N);
    }
};