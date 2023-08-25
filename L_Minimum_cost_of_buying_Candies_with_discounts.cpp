class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ans = 0;
        for(int i=cost.size()-1; i>=0; i=i-3)
        {
            ans += cost[i];
            if(i-1 >= 0)
            {
                ans += cost[i-1];
            }
        }

        return ans;
    }
};