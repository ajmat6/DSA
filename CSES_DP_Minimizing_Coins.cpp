#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;

int solve(int money, vi& coins, vi& dp)
{
    if(money == 0) return 0;
    if(money < 0) return INT_MAX;

    if(dp[money] != -1) return dp[money];

    int ans = INT_MAX;
    for(int i=0; i<coins.size(); i++)
    {
        int temp = solve(money - coins[i], coins, dp);
        if(temp != INT_MAX) ans = min(ans, 1 + temp);
    }

    return dp[money] = ans;
}

int solve2(int moneyy, vi& coins)
{
    vi dp (moneyy + 1, INT_MAX);
    dp[0] = 0;

    for(int money=1; money<=moneyy; money++)
    {
        int ans = INT_MAX;
        for(int i=0; i<coins.size(); i++)
        {
            int temp = INT_MAX;
            if(money - coins[i] >= 0) temp = dp[money - coins[i]];
            if(temp != INT_MAX) ans = min(ans, 1 + temp);
        }

        dp[money] = ans;
    }

    return dp[moneyy];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, money;
    cin >> n >> money;

    vi coins (n);
    for(int i=0; i<n; i++) cin >> coins[i];

    // vi dp (money + 1, -1);
    // int ans = solve(money, coins, dp);

    int ans = solve2(money, coins);
    if(ans == INT_MAX) cout << "-1";
    else cout << ans;    

    return 0;
}