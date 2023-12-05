#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;

int solve(int money, vi& coins, int sum, vi& dp)
{
    if(sum == money) return 0;
    if(sum > money) return INT_MAX;

    if(dp[sum] != -1) return dp[sum];

    int ans = INT_MAX;
    for(int i=0; i<coins.size(); i++)
    {
        if(sum + coins[i] <= money)
        {
            int temp = solve(money, coins, sum + coins[i], dp);
            if(temp != INT_MAX) ans = min(ans, 1 + temp);
        }
    }

    return dp[sum] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, money;
    cin >> n >> money;

    vi coins (n);
    for(int i=0; i<n; i++) cin >> coins[i];
    vi dp (n + 1, -1);
    int ans = solve(money, coins, 0 ,dp);
    if(ans == INT_MAX) cout << -1;
    else cout << ans;    

    return 0;
}