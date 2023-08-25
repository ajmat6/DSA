class Solution {
public:
    // function for finding next possible index:
    int BinarySearch(int i, int j, int target, vector<vector<int>>& v)
    {
        int low = i;
        int high = j;
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(v[mid][0] >= target)
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
    int solve(vector<vector<int>>& v, int index)
    {
        // Base Case:
        if(index == v.size() || index == -1) return 0;

        // take present index: also find next possible index:
        int nextIndex = BinarySearch(index, v.size()-1, v[index][1], v);
        int take = v[index][2] + solve(v, nextIndex);

        int notTake = 0 + solve(v, index+1);

        int ans = max(take, notTake);
        return ans;
    }

    // Memorisation:
    int solve2(vector<vector<int>>& v, int index, vector<int>& dp)
    {
        // Base Case:
        if(index == v.size() || index == -1) return 0;

        if(dp[index] != -1) return dp[index];

        // take present index: also find next possible index:
        int nextIndex = BinarySearch(index, v.size()-1, v[index][1], v);
        int take = v[index][2] + solve2(v, nextIndex, dp);

        int notTake = 0 + solve2(v, index+1, dp);

        int ans = max(take, notTake);
        dp[index] = ans;
        return ans;
    }

    // Tabulation:
    int solve3(vector<vector<int>>& v)
    {
        vector<int> dp (v.size()+1, 0);
        // Base Case:

        for(int index=v.size()-1; index>=0; index--)
        {
            // take present index: also find next possible index:
            int nextIndex = BinarySearch(index, v.size()-1, v[index][1], v);

            int take = 0;
            if(nextIndex == -1)
            {
                take = v[index][2] + 0;
            }

            else 
            {
                take = v[index][2] + dp[nextIndex];
            }

            int notTake = 0 + dp[index+1];

            int ans = max(take, notTake);
            dp[index] = ans;
        }

        return dp[0];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        for(int i=0;  i<startTime.size(); i++)
        {
            v.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(v.begin(), v.end());

        // Recursion:
        // return solve(v, 0);

        // Memorisation:
        // vector<int> dp (v.size(), -1);
        // return solve2(v, 0, dp);

        // Tabulation:
        return solve3(v);
    }
};