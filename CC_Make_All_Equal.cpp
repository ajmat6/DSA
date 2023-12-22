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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        ll n, m;
        cin >> n >> m;

        vll temp (n);
        for(ll i=0; i<n; i++) cin >> temp[i];

        // find max frequency:
        ll maxi = INT_MIN;
        ll mini = INT_MAX;
        for(auto i: temp)
        {
            mini = min(mini, i);
            maxi = max(maxi, i);
        }

        ll count = 0;
        for(auto i: temp) count += (maxi - i);

        ll ans = max(maxi - mini, (count + m - 1) / m);

        cout << ans << "\n";
    }

    return 0;
}