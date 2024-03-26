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

    while(t--) {
        int n;
        cin >> n;

        // by solving inequilities:
        // vector<pll> b;
        // for(int i=0; i<n; i++) {
        //     int size;
        //     cin >> size;
        //     ll maxi = LLONG_MIN;
        //     for(int j=0; j<size; j++) {
        //         ll x;
        //         cin >> x;
        //         maxi = max(maxi, x - j);
        //     }

        //     b.pb({maxi, size});
        // }

        // sort(b.begin(), b.end());
        // ll ans = INT_MIN;
        // ll sum = 0;
        // for(auto i: b) {
        //     ans = max(ans, i.F - sum);
        //     sum += i.S;
        // }

        // cout << ans + 1 << "\n";


        // by using binary search:
        vector<pll> power;
        for(ll i=0; i<n; i++) {
            int size;
            cin >> size;
            ll maxi = LLONG_MIN;
            for(int j=0; j<size; j++) {
                ll x;
                cin >> x;
                maxi = max(maxi, x - j + 1);
            }

            power.pb({maxi, size});
        }

        sort(power.begin(), power.end());
        ll low = power[0].F; ll high = power[power.size() - 1].F; ll ans;

        while(low <= high) {
            ll mid = low + (high - low) / 2;
            ll checkPower = mid;

            bool poss = true;
            for(auto i: power) {
                if(checkPower >= i.first) checkPower += i.second;
                else {
                    poss = false;
                    break;
                }
            }

            if(poss) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        cout << ans << "\n";
    }

    return 0;
}