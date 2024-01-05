class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b)
    {
        // we are sorting here on the basis of lower range but if two index lower range is equal, then that range will come first who can water upto larger range:
        if(a[0] == b[0])
        {
            return a[1] > b[1];
        }

        else return a[0] < b[0];
    }

    int solve(int n, vector<vector<int>>& temp, int index, int lower, vector<int>& dp)
    {
        if(lower >= n) return 0; // if whole garden is watered
        if(index == n + 1) return 1e6; // if whole range checked and garden is not watered

        if(dp[index] != -1) return dp[index];

        // int take = 1e6;
        // int notTake = 1e6;

        // taking present index if it is possible:
        int ans = 1e6;
        for(int i=index; i<n+1; i++)
        {
            if(temp[i][0] <= lower)
            {
                ans = min(ans, 1 + solve(n, temp, i+1, temp[i][1], dp));
            }
            else break;
        }
        // if(temp[index][0] <= lower)
        // {
        //     take = 1 + solve(n, temp, index+1, temp[index][1], dp);
        //     notTake = solve(n, temp, index+1, lower, dp);
        // }

        // int ans = min(take, notTake);
        return dp[index] = ans;
    }

    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> temp (n+1, vector<int> (2, 0));

        // creating range for each index:
        for(int i=0; i<ranges.size(); i++)
        {
            temp[i] = {i - ranges[i], i + ranges[i]};
        }
        sort(temp.begin(), temp.end(), compare);

        vector<int> dp (n+2, -1);
        int ans = solve(n, temp, 0, 0, dp);
        return ans == 1e6 ? -1 : ans;


        // Greedy:

        // vector<int> reach (n + 1, 0);

        // for(int i=0; i<ranges.size(); i++)
        // {
        //     int lower = max(0, i - ranges[i]);
        //     int higher = i + ranges[i];
        //     reach[lower] = max(reach[i], higher);
        // }

        // int taps = 0;
        // int areaCovered = 0;
        // int currArea = 0;

        // for(int i=0; i<reach.size(); i++)
        // {
        //     if(i > areaCovered) return -1; // if areaCovered is still at 0 and i moved to 1, then area between 0 and 1 is not watered and hence whole garden cannot be watered

        //     // if checking is now greater than total area that is alreday watered, then we have to use one more tap
        //     if(i > currArea)
        //     {
        //         taps++;
        //         currArea = areaCovered;
        //     }

        //     areaCovered = max(areaCovered, reach[i]);
        // }

        // return taps;
    }
};