class Solution {
public:
    // Binary search for finding valid index:
    int BinarySearch(vector<vector<int>>& intervals, int i, int j, int target)
    {
        int low = i;
        int high = j;
        int ans = -1; // return -1 as default if no index containing greater element than target is found:

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(intervals[mid][0] >= target)
            {
                ans = mid;
                high = mid - 1;
            }

            else 
            {
                low = mid + 1;
            }
        }

        return ans;
    }

    // Recursion:
    int solve(vector<vector<int>>& intervals, int index)
    {
        if(index == intervals.size() || index == -1) return 0;

        // include case: Assuming that current index is a valid index for including and finding next possibpe index:
        int i = BinarySearch(intervals, index+1, intervals.size()-1, intervals[index][1]);
        int  include  = 1 + solve(intervals, i);

        // Exclude case:
        int exclude = 0 + solve(intervals, index+1);

        int ans = max(include, exclude);
        return ans;
    }

    // Memorisation:
    int solve2(vector<vector<int>>& intervals, int index, vector<int>& dp)
    {
        if(index == intervals.size() || index == -1) return 0;

        // check for dp:
        if(dp[index] != -1) return dp[index];

        // include case: Assuming that current index is a valid index for including and finding next possibpe index:
        int i = BinarySearch(intervals, index+1, intervals.size()-1, intervals[index][1]);
        int  include  = 1 + solve2(intervals, i, dp);

        // Exclude case:
        int exclude = 0 + solve2(intervals, index+1, dp);

        int ans = max(include, exclude);
        dp[index] = ans;
        return ans;
    }

    // Tabulation:
    int solve3(vector<vector<int>>& intervals)
    {
        vector<int> dp (intervals.size()+1, 0);
        // if(index == intervals.size() || index == -1) return 0;

        for(int index=intervals.size()-1; index>=0; index--)
        {
            // include case: Assuming that current index is a valid index for including and finding next possibpe index:
            int i = BinarySearch(intervals, index+1, intervals.size()-1, intervals[index][1]);
            int include = 0;
            if(i != -1)
            {
                include  = 1 + dp[i];
            }
            else
            {
                include = 1 + 0;
            }

            // Exclude case:
            int exclude = 0 + dp[index+1];

            int ans = max(include, exclude);
            dp[index] = ans;
        }

        return dp[0];
    }

    // sorting intervals on the basis of ending time for greedy approach:
    static bool compare(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        // int maxInclude = solve(intervals, 0); // max no elements that you can include
        // int minRemove = intervals.size() - maxInclude; // so min no elements you have  to remove
        // return minRemove;

        // Memorisation:
        // vector<int> dp (intervals.size()+1, -1);
        // int maxInclude = solve2(intervals, 0, dp); // max no elements that you can include
        // int minRemove = intervals.size() - maxInclude; // so min no elements you have  to remove
        // return minRemove;

        // Tabulation:
        // int maxInclude = solve3(intervals); // max no elements that you can include
        // int minRemove = intervals.size() - maxInclude; // so min no elements you have  to remove
        // return minRemove;

        // Greedy Approch:
        sort(intervals.begin(), intervals.end(), compare);
        int prev = intervals[0][1];
        int maxInclude = 1;

        for(int index=1; index<intervals.size(); index++)
        {
            if(intervals[index][0] >= prev)
            {
                maxInclude++;
                prev = intervals[index][1];
            }
        }

        return intervals.size() - maxInclude;
    }
};