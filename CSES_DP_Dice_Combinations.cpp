#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
int mod = 1000000007;

int solve(int n, int sum, vector<int>& dp)
{
    if(sum == n) return 1;
    if(sum > n) return 0;

    if(dp[sum] != -1) return dp[sum];

    int ans = 0;
    for(int i=1; i<=6; i++)
    {
        if(sum + i <= n) ans = (ans + solve(n, sum + i, dp)) % mod;
    }

    return dp[sum] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ans = 0;
    vector<int> dp (n + 1, -1);
    for(int i=1; i<=6; i++)
    {
        if(i <= n) ans = (ans + solve(n, i, dp)) % mod;
    }
    cout << ans;

    return 0;
}