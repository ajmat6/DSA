class Solution {
public:
    int findIndex(vector<vector<int>>& offers, int value, int index)
    {
        int ans = -1;
        int low = index;
        int high = offers.size()-1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(offers[mid][0] > value) 
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
    int solve(vector<vector<int>>& offers, int index, vector<int>& dp)
    {
        if(index == offers.size()) return 0;

        if(dp[index] != -1) return dp[index];
        
        int ans = 0;
        // not selling current index houses:
        int notSell = solve(offers, index+1, dp);

        // selling current index houses:
        // if you are selling current house, then you have to ensure that next lower index of next index should be greater than present higher value:
        int nextIndex = findIndex(offers, offers[index][1], index+1);
        int sell = offers[index][2] + (nextIndex == -1 ? 0 : solve(offers, nextIndex, dp));

        ans = max(sell, notSell);
        return dp[index] = ans;
    }

    int solve2(vector<vector<int>>& offers)
    {
        vector<int> dp (offers.size()+1, 0);

        for(int index=offers.size()-1; index>=0; index--)
        {
            int ans = 0;
            // not selling current index houses:
            int notSell = dp[index+1];

            // selling current index houses:
            // if you are selling current house, then you have to ensure that next lower index of next index should be greater than present higher value:
            int nextIndex = findIndex(offers, offers[index][1], index+1);
            int sell = offers[index][2] + (nextIndex == -1 ? 0 : dp[nextIndex]);

            ans = max(sell, notSell);
            dp[index] =  ans;
        }
        
        return dp[0];
    } 

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        // vector<int> dp (offers.size(), -1);
        // return solve(offers, 0, dp);

        // Tabulation:
        return solve2(offers);
    }
};