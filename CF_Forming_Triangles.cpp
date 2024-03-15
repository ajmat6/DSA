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

bool cmp(vi& a, vi& b) {
    return a[0] > b[0];
}

int fact(int a) {
    if(a == 0) return 1;
    if(a == 1) return 1;
    else return a * fact(a - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        vll a (n);
        for(ll i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        if(n < 3) {
            cout << "0\n";
            continue;
        }

        map<ll, ll> mp;
        for(ll i=0; i<n; i++) mp[a[i]]++;

        ll ans = 0;
        for(auto i: mp) {
            ll freq = i.S;
            ans += (freq * (freq - 1) *  (freq - 2)) / 6;

            ll selectTwo = (freq * (freq - 1) )/ 2;
            ll noOFNosLessThancurr = lower_bound(a.begin(), a.end(), i.F) - a.begin();
            ans += (selectTwo * noOFNosLessThancurr);
        }

        cout << ans << "\n";
    }

    return 0;
}