class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        int ans = num;
        for(int i=0; i<t; i++)
        {
            ans = ans + 2;
        }
        
        return ans;
    }
};