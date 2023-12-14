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

int solve(int num, vi& dp)
{
    if(num == 0) return 0;
    if(num < 0) return INT_MAX;

    if(dp[num] != -1) return dp[num];

    string s = to_string(num);
    int ans = INT_MAX;
    for(int i=0; i<s.size(); i++)
    {
        int no = s[i] - '0';
        if(no != 0)
        {
            int temp = solve(num - no, dp);
            if(temp != INT_MAX) ans = min(ans, 1 + temp);
        }
    }

    return dp[num] = ans;
}

int tab(int numm)
{
    vi dp (numm + 1, 0);
    for(int num=1; num<=numm; num++)
    {
        string s = to_string(num);
        int ans = INT_MAX;
        for(int i=0; i<s.size(); i++)
        {
            int no = s[i] - '0';
            if(no != 0)
            {
                int temp = INT_MAX;
                if(num - no >= 0) temp = dp[num - no];
                if(temp != INT_MAX) ans = min(ans, 1 + temp);
            }
        }

        dp[num] = ans;
    }

    return dp[numm];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    // vi dp (n + 1, -1);
    // cout << solve(n, dp);
    cout << tab(n);

    return 0;
}