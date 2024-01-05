#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& nums, int m, int index, int sum, vector<vector<int>>& dp)
{
    if(index == n)
    {
        if(sum == -1) return 0;
        if(sum % m == 0)  return 1;
        else return 0;
    }

    if(dp[index][sum + 1] != -1) return dp[index][sum];

    // take current index element in sum:
    int take;
    if(sum == -1) take = solve(n, nums, m, index + 1, nums[index], dp);
    else take = solve(n, nums, m, index + 1, sum + nums[index], dp);
    int notTake = solve(n, nums, m, index + 1, sum, dp);

    if(take || notTake) return dp[index][sum + 1] = 1;
    else return dp[index][sum + 1] = 1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> num (n);
    for(int i=0; i<n; i++) cin >> num[i];

    if(n >= m) cout << "YES\n"; // pegion hole principal dry run about this

    vector<vector<int>> dp (n + 1, vector<int> (m + 1, -1));
    int ans = solve(n, num, m, 0, 0);
    if(ans) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}