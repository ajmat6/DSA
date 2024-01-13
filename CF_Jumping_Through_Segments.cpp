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
            maxi = max(maxi, max(a, b));
        }

        ll low = temp[0].first;
        ll high = maxi;
        ll ans = INT_MAX;

        // cout << maxi << " ";

        while(low <= high) {
            ll mid = low + (high - low) / 2;
            // cout << mid << " ";

            // check mid is possible or not:
            bool poss = true;
            pair<int, int> seg = {0, mid};
            for(int i=0; i<n; i++) {
                int lower = temp[i].first;
                int higher = temp[i].second;

                if(lower > seg.second || higher < seg.first) {
                    low = mid + 1;
                    poss = false;
                    break;
                }

                else {
                    if(lower >= seg.first && higher <= seg.second) {
                        seg = {lower, higher};
                        ll leftExpand = max((ll) 0, seg.first - mid);
                        ll rightExpand = seg.second + mid;
                        // cout << leftExpand << " " << rightExpand << " ";
                        seg = {leftExpand, rightExpand};
                    } 
                    else if(lower >= seg.first && higher > seg.second){
                        seg = {lower, seg.second};
                        ll leftExpand = max((ll) 0, seg.first - mid);
                        ll rightExpand = seg.second + mid;
                        seg = {leftExpand, rightExpand};
                    } 
                    else if(lower < seg.first && higher <= seg.second){
                        seg = {seg.first, higher};
                        ll leftExpand = max((ll) 0, seg.first - mid);
                        ll rightExpand = min(maxi, seg.second + mid);
                        seg = {leftExpand, rightExpand};
                    }
                }
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