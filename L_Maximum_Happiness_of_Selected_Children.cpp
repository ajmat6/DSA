class Solution {
public:
    long long maximumHappinessSum(vector<int>& happy, int k) {
        sort(happy.begin(), happy.end());
        long long count = 0;
        long long ans = 0;
        for(int i=happy.size()-1; i>=0; i--) {
            if(k > 0 && happy[i] - count > 0) {
                ans += happy[i] - count;
                count++;
                k--;
            } 
            
            else break;
        }
        
        return ans;
    }
};