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

    while(t--) {
        ll n;
        cin >> n;

        vector<pll> temp;
        ll maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            ll a, b;
            cin >> a >> b;
            temp.pb({a, b});
        }

        ll low = temp[0].F; ll high = 1e9; ll ans = INT_MAX;
        while(low <= high) {
            ll mid = low + (high - low) / 2;

            bool poss = true;
            pair<int, int> seg = {0, mid};
            for(int i=0; i<n; i++) {
                int lower = temp[i].F;
                int higher = temp[i].S;

                if(lower > seg.S || higher < seg.F) {
                    low = mid + 1;
                    poss = false;
                    break;
                }

                seg.F = max(seg.F, lower);
                seg.S = min(seg.S, higher);
                ll leftExpand = max((ll) 0, seg.F - mid);
                ll rightExpand = seg.S + mid;
                seg = {leftExpand, rightExpand};
            }

            if(poss) {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}