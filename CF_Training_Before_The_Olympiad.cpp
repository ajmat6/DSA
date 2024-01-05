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

        vll a (n);
        for(ll i=0; i<n; i++) cin >> a[i];

        ll count = 0;
        ll sum = a[0];

        vll ans;
        ans.pb(a[0]);
        if(a[0] % 2 == 1) count++;

        for(ll i=1; i<n; i++)
        {
            sum += a[i];
            if(a[i] % 2 == 1) count++;

            ll quo = count / 3;
            ll rem = count % 3;

            if(rem == 0 || rem == 2) rem = 0;
            else rem = 1;

            ans.push_back(sum - quo - rem);
        }

        for(ll i=0; i<ans.size(); i++) cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}