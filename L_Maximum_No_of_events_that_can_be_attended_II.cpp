class Solution {
public:
    // to find next possible index for the event to participate:
    int BinarySearch(int index, vector<vector<int>>& events, int target)
    {
        int low = index;
        int high = events.size()-1;
        int ans = -1; // if index for greater element is not found return -1

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(events[mid][0] > target) // possible case
            {
                ans = mid;
                high = mid -1;
            }

            else 
            {
                low = mid + 1;
            }
        }

        return ans;
    }

    // Recursion: Diff approach
    int solve(vector<vector<int>>& events, int k, int index, int prev)
    {
        if(index == events.size() || k == 0) return 0;

        int take = 0;
        int notTake = 0;
        int notPossible = 0;

        if(events[index][0] > prev)
        {
            // take case:
            take = events[index][2] + solve(events, k-1, index+1, events[index][1]);

            // not take case:
            notTake = 0 + solve(events, k, index+1, prev);
        }

        else
        {
            notPossible = solve(events, k, index+1, prev);
        }

        int ans = max(take, max(notTake, notPossible));
        return ans;
    }

    // Memorisation 1st approach:
    int solveMem(vector<vector<int>>& events, int k, int index, int prev, vector<vector<int>>& dp)
    {
        if(index == events.size() || k == 0) return 0;

        if(events[index][0] <= prev)
        {
            return solveMem(events, k, index+1, prev, dp);
        }

        if(dp[index][k] != -1) return dp[index][k];

        // take case:
        int take = events[index][2] + solveMem(events, k-1, index+1, events[index][1], dp);

        // not take case:
        int notTake = 0 + solveMem(events, k, index+1, prev, dp);

        int ans = max(take, notTake);
        dp[index][k] = ans;
        return ans;
    }

    // Memorisation 2nd approach:
    int solveMem2(vector<vector<int>>& events, int k, int index, vector<vector<int>>& dp)
    {
        if(index == events.size() || k == 0 || index == -1) return 0;

        if(dp[index][k] != -1) return dp[index][k];

        // take case:
        int nextIndex = BinarySearch(index+1, events, events[index][1]);
        int take = events[index][2] + solveMem2(events, k-1, nextIndex, dp);

        // not take case:
        int notTake = 0 + solveMem2(events, k, index+1, dp);

        int ans = max(take, notTake);
        dp[index][k] = ans;
        return ans;
    }

    // Tabulation:
    int solveTab(vector<vector<int>>& events, int no)
    {
        vector<vector<int>> dp(events.size()+1, vector<int> (no+1, 0));

        for(int index=events.size()-1; index>=0; index--)
        {
            for(int k=1; k<=no; k++)
            {
                // take case:
                int nextIndex = BinarySearch(index+1, events, events[index][1]);
                int take = 0;
                if(nextIndex != -1)
                {
                    take = events[index][2] + dp[nextIndex][k-1];
                }
                else 
                {
                    take = events[index][2] + 0;
                }

                // not take case:
                int notTake = 0 + dp[index+1][k];

                int ans = max(take, notTake);
                dp[index][k] = ans;
            }
        }
        return dp[0][no];
    }

    int maxValue(vector<vector<int>>& events, int k) {
        // vector<int> upper;
        // for(auto i: events) upper.push_back(i[0]);

        sort(events.begin(), events.end());
        // sort(upper.begin(), upper.end());

        // return solve(events, k, 0, -1);

        // vector<vector<int>> dp(events.size(), vector<int> (k+1, -1));
        // return solveMem(events, k, 0, 0, dp);// first method
        // return solveMem2(events, k, 0, dp);

        // Tabulation:
        return solveTab(events, k);
    }
};