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

int solve(int index, int sum, vi& prices, vi& pages, vvi& dp)
{
    if(index == prices.size()) return 0;
    if(sum <= 0) return 0;

    if(dp[index][sum] != -1) return dp[index][sum];

    // select and not select current index book:
    int take = 0;
    if(sum - prices[index] >= 0) take = pages[index] + solve(index + 1, sum - prices[index], prices, pages, dp);
    int notTake = 0 + solve(index + 1, sum, prices, pages, dp);

    return dp[index][sum] = max(take, notTake);
}

int solve2(int summ, vi& prices, vi& pages)
{
    vvi dp (prices.size() + 1, vi (summ + 1, 0));

    for(int index=prices.size()-1; index>=0; index--)
    {
        for(int sum=1; sum<=summ; sum++)
        {
            int take = 0;
            if(sum - prices[index] >= 0) take = pages[index] + dp[index + 1][sum - prices[index]];
            int notTake = 0 + dp[index + 1][sum];

            dp[index][sum] = max(take, notTake);
        }
    }

    return dp[0][summ];
}

int solve3(int summ, vi& prices, vi& pages)
{
    vi curr (summ + 1, 0);
    vi next (summ + 1, 0);

    for(int index=prices.size()-1; index>=0; index--)
    {
        for(int sum=1; sum<=summ; sum++)
        {
            int take = 0;
            if(sum - prices[index] >= 0) take = pages[index] + next[sum - prices[index]];
            int notTake = 0 + next[sum];

            curr[sum] = max(take, notTake);
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

    int n, x;
    cin >> n >> x;

    vi prices (n);
    vi pages (n);

    for(int i=0; i<n; i++) cin >> prices[i];
    for(int i=0; i<n; i++) cin >> pages[i];

    // vvi dp (n + 1, vi (x + 1, -1));
    // cout << solve(0, x, prices, pages, dp);
    // cout << solve2(x, prices, pages);
    cout << solve3(x, prices, pages);

    return 0;
}