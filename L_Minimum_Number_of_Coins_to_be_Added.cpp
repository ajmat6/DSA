class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        int sum = 0; // to track sum of coins at each index
        int i = 0;
        while(sum < target)
        {
            // if current coin value is less than the sum required (sum + 1 as I have already all values coins (anyhow) till sum), add it to sum keeping the index of coins is within boundaries
            if(i < coins.size() && coins[i] <= sum + 1)
            {
                sum += coins[i];
                i++;
            }

            // if the current coin value is greater than sum + 1 (that is required), add a coins and now your sum will reach 2 * currentsum + 1 (think about binary representation of a number 1, 2, 4, 8, 16, 32......)
            else 
            {
                sum = 2 * sum + 1;
                ans++;
            }
        }

        return ans;
    }
};