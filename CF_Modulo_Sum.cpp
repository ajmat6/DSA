#include<bits/stdc++.h>
using namespace std;

bool solve(int n, vector<int>& nums, int m, int index, int sum)
{
    if(index == n)
    {
        if(sum == 0) return false
        if(sum % m == 0)  return true;
        else return false;
    }

    // take current index element in sum:
    bool take = solve(n, nums, m, index + 1, sum + nums[index]);
    bool notTake = solve(n, nums, m, index + 1, sum);

    if(take || notTake) return true;
    else return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> num (n);
    for(int i=0; i<n; i++) cin >> num[i];

    bool ans = solve(n, num, m, 0, 0);
    if(ans) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}