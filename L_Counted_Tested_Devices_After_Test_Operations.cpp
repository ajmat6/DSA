class Solution {
public:
    int countTestedDevices(vector<int>& bt) {
        int ans = 0;
        for(int i=0; i<bt.size(); i++)
        {
            if(bt[i] > 0)
            {
                ans++;
                for(int j=i+1; j<bt.size(); j++)
                {
                    bt[j] = max(0, bt[j] - 1);
                }
            }
        }
        return ans;
    }
};