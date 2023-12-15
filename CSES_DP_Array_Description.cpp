#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
const int mod = 1000000007;

int solve(vi& nums, int n, int m, int index, vi& dp)
{
    if(index == n) return 1;

    // check dp:
    if(dp[index] != -1) return dp[index];

    int ans = 0;
    if(nums[index] == 0) 
    {
        for(int i=1; i<=m; i++)
        {
            nums[index] = i;
            if(index != 0 && abs(nums[index] - nums[index - 1]) <= 1) ans = (ans + solve(nums, n, m, index + 1, dp)) % mod;
            else if(index == 0) ans = (ans + solve(nums, n, m, index + 1, dp)) % mod;
            nums[index] = 0;
        }
    }

    else
    {
        if(index == 0) ans = (ans + solve(nums, n, m, index + 1, dp)) % mod;
        else 
        {
            if(abs(nums[index] - nums[index - 1]) <= 1) ans = (ans + solve(nums, n, m, index + 1, dp)) % mod;
        }
    }

    return dp[index] = ans % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi nums (n);
    for(int i=0; i<n; i++) cin >> nums[i];
    vi dp (n, -1);
    cout << solve(nums, n, m, 0, dp) % mod;

    return 0;
}