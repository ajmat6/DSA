class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // find satisfied customers intially:
        int satis = 0;
        for(int i=0; i<grumpy.size(); i++) {
            if(!grumpy[i]) satis += customers[i];
        }

        // maintain a sliding window: first window
        for(int i=0; i<minutes; i++) {
            if(grumpy[i]) satis += customers[i];
        }

        int ans = satis; 
        int low = 1; int high = minutes;
        while(high < customers.size()) {
            if(grumpy[low - 1]) satis -= customers[low - 1];
            if(grumpy[high]) satis += customers[high];
            ans = max(ans, satis);
            low++; high++;
        }
        return ans;
    }
};