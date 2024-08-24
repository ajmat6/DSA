class Solution {
public: 
    int solve(int full, int exc, int rem) {
        // base case:
        if(full == 0) return 0;
        return full + solve((full + rem) / exc, exc, (full + rem) % exc);
    }

    int numWaterBottles(int numBottles, int numExchange) {
        // using recursion:
        // return solve(numBottles, numExchange, 0);

        // using loop:
        int ans = numBottles;
        while(numBottles >= numExchange) {
            ans += numBottles / numExchange;
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }
        return ans;
    }
};