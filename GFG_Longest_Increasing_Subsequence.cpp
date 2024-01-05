class Solution
{
    public:
    int solve(int n, int a[], int index, int prev, vector<vector<int>>& dp)
    {
        if(index == n) return 0;
        
        if(dp[index][prev + 1] != -1) return dp[index][prev + 1];
        
        // take case:
        int include = 0;
        if(prev == -1 || a[index] > a[prev]) include = 1 + solve(n, a, index + 1, index, dp);
        
        // not take case:
        int exclude = 0 + solve(n, a, index + 1, prev, dp);
        
        int ans = max(include, exclude);
        
        return dp[index][prev + 1] = ans;
    }
    
    int tab(int n, int a[])
    {
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));
        
        
        for(int index=n-1; index>=0; index--)
        {
            for(int prev=index-1; prev>=-1; prev--)
            {
                // take case:
                int include = 0;
                if(prev == -1 || a[index] > a[prev]) include = 1 + dp[index+1][index+1];
                
                // not take case:
                int exclude = 0 + dp[index+1][prev+1];
                
                int ans = max(include, exclude);
                
                dp[index][prev+1] = ans;
            }
        }
        
        
        return dp[0][0];
    }
    
    int SO(int n, int a[])
    {
        vector<int> next (n+1, 0); // index + 1 ki jagah:
        vector<int> curr (n+1, 0);
        
        
        for(int index=n-1; index>=0; index--)
        {
            for(int prev=index-1; prev>=-1; prev--)
            {
                // take case:
                int include = 0;
                if(prev == -1 || a[index] > a[prev]) include = 1 + next[index+1];
                
                // not take case:
                int exclude = 0 + next[prev+1];
                
                int ans = max(include, exclude);
                
                curr[prev+1] = ans;
            }
            
            next = curr;
        }
        
        
        return curr[0];
    }
    
    // LIS Striver Snippet:
    int striver(int n, int a[])
    {
        vector<int> dp (n, 1);
        
        int ans = 1;
        for(int index=0; index<n; index++)
        {
            for(int prev=0; prev<index; prev++)
            {
                if(a[index] > a[prev] && dp[prev] + 1 > dp[index])
                {
                    dp[index] = 1 + dp[prev];
                }
            }
            ans = max(ans, dp[index]);
        }
        
        return ans;
    }
    
    // Using binary search:
    int binary(int n, int a[]){
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i=0; i<n; i++)
        {
            // if current index element is satisfying LIS condition:
            if(a[i] > ans.back()) ans.push_back(a[i]);
            
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
            
        }
        
        return ans.size();
    }
    
    
    int longestSubsequence(int n, int a[])
    {
        // Memorisation + Recursion:
        // vector<vector<int>> dp (n, vector<int> (n + 1, -1));
        // return solve(n, a, 0, -1, dp);
        
        // tabulation:
        // return tab(n, a);
        
        // space optimisation:
        // return SO(n, a);
        
        // Stiver snippet:
        // return striver(n, a);
        
        // binary search:
        return binary(n, a);
    }
};