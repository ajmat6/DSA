class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n, int k, int no, vector<int>& temp)
    {
        // Base case:
        if(k == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(no > n) return;

        // selecting current no:
        if(no <= n)
        {
            temp.push_back(no);
            solve(n, k-1, no+1, temp);
        }

        temp.pop_back();
        solve(n, k, no+1, temp);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(n, k, 1, temp);
        return ans;
    }
};