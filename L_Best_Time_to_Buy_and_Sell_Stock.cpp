class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lastMin = prices[0];
        int ans = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] >= lastMin) ans = max(ans, prices[i] - lastMin);
            lastMin = min(lastMin, prices[i]);
        }
        return ans;
    }
};