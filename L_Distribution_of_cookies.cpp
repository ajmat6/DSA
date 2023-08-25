class Solution {
public:
    int solve(vector<int>& cookies, vector<int>& v, int index)
    {
        // Base Case:
        if(index == cookies.size())
        {
            int ans = 0;
            for(auto a: v) ans = max(ans, a);
            return ans;
        }

        int ans = INT_MAX;
        for(int i=0; i<v.size(); i++)
        {
            v[i] += cookies[index];
            int tempAssign = solve(cookies, v, index+1);
            ans = min(ans, tempAssign);
            v[i] -= cookies[index];
        }

        return ans;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v (k);
        return solve(cookies, v, 0);
    }
};