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
ll prefix[100001] = {0};

ll solve(ll len, ll k, vector<int>& dp)
{
    if(len == 0) return 1;

    if(dp[len] != -1) return dp[len];

    // taking red presently:
    ll red = solve(len - 1, k, dp) % mod;
    
    // taking white presently:
    ll white = 0;
    if(len - k >= 0) white = solve(len - k, k, dp) % mod;

    return dp[len] = (red + white) % mod;
}

void solvePrefix(ll k)
{
    vector<int> dp (100001, -1);
    for(int i=1; i<100001; i++) prefix[i] = (prefix[i - 1] + solve(i, k, dp)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, k;
    cin >> t >> k;

    solvePrefix(k); // calculationg all possible ways to eat at each index + previous index:

    while(t--)
    {
        ll a, b;
        cin >> a >> b;

        cout << (prefix[b] - prefix[a-1] + mod ) % mod << "\n";
    }

    return 0;
}