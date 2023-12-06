#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
const int mod = 1000000007;

int solve(int sum, vi& coins, vi& dp)
{
    if(sum == 0) return 1;
    if(sum < 0) return 0;

    if(dp[sum] != -1) return dp[sum];

    int ans = 0;
    for(int i=0; i<coins.size(); i++)
    {
        ans = (ans + solve(sum - coins[i], coins, dp)) % mod;
    }

    return dp[sum] = ans;
}

int solve2(int summ, vi& coins)
{
    vi dp (summ + 1, 0);
    dp[0] = 1;

    for(int sum=1; sum<=summ; sum++)
    {
        int ans = 0;
        for(int i=0; i<coins.size(); i++)
        {
            if(sum - coins[i] >= 0) ans = (ans + dp[sum - coins[i]]) % mod;
        }

        dp[sum] = ans;
    }

    return dp[summ];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sum;
    cin >> n >> sum;

    vi coins (n);
    for(int i=0; i<n; i++) cin >> coins[i];

    vi dp (sum + 1, -1);
    cout << solve(sum, coins, dp) % mod;    

    // cout << solve2(sum, coins);

    return 0;
}