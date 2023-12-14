#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
const int mod = 1000000007;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int solve(int sum, int index, vi& coins, vvi& dp)
{
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(index == coins.size()) return 0;

    if(dp[index][sum] != -1) return dp[index][sum];

    int take = solve(sum - coins[index], index, coins, dp);
    int notTake = solve(sum, index + 1, coins, dp);
    int ans = (take + notTake) % mod;

    return dp[index][sum] = ans;
}

int solve2(int summ, vi& coins)
{
    vvi dp (coins.size() + 1, vi (summ + 1, 0));
    for(int i=0; i<dp.size(); i++)
    {
        dp[i][0] = 1;
    }

    for(int index=coins.size()-1; index>=0; index--)
    {
        for(int sum=1; sum<=summ; sum++)
        {
            int take = 0;
            if(sum - coins[index] >= 0) take = dp[index][sum-coins[index]];
            int notTake = dp[index + 1][sum];
            int ans = (take + notTake) % mod;

            dp[index][sum] = ans;
        }
    }

    return dp[0][summ];
}

int solve3(int summ, vi& coins)
{
    vi curr (summ + 1, 0);
    vi next (summ + 1, 0);
    curr[0] = 1;
    next[0] = 1;

    for(int index=coins.size()-1; index>=0; index--)
    {
        for(int sum=1; sum<=summ; sum++)
        {
            int take = 0;
            if(sum - coins[index] >= 0) take = curr[sum-coins[index]];
            int notTake = next[sum];
            int ans = (take + notTake) % mod;

            curr[sum] = ans;
        }
        next = curr;
    }

    return curr[summ];
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

    // vvi dp (n + 1, vi (sum + 1, -1));
    // cout << solve(sum, 0, coins, dp) % mod;    

    // cout << solve2(sum, coins); // tabulation (iterative dp)

    cout << solve3(sum, coins); // space optimisation

    return 0;
}