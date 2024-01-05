class Solution {
public:
    void solve(int k, int n, int start, vector<int> temp, vector<vector<int>>& ans)
    {
        if(k == 0 && n == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(k == 0 && n != 0) return;
        if(k != 0 && n <= 0) return;

        for(int i=start; i<=9; i++)
        {
            temp.push_back(i);
            solve(k - 1, n - i, i + 1, temp, ans);
            temp.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        solve(k, n, 1, {}, ans);
        return ans;
    }
};