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

    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        vll temp (n);
        for(ll i=0; i<n; i++) cin >> temp[i];

        vll v;
        v.pb(temp[0]);
        ll smallest = temp[0];
        for(ll i=1; i<n; i++)
        {
            smallest = min(smallest, temp[i]);
            if(temp[i] == smallest) v.pb(temp[i]);
        }

        ll ans = n;
        reverse(v.begin(), v.end());
        for(ll i=0; i<v.size(); i++)
        {
            ans = min(ans, v[i] + n - (i + 1));
        }

        cout << ans << "\n";
    }

    return 0;
}