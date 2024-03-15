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
        ll n, k;
        cin >> n >> k;

        if(k >= n) cout << "1\n";
        else {
            ll ans = INT_MAX;
            for(ll i=1; i*i<=n; i++) {
                if(n % i == 0) {
                    // taking i as the pakage I am taking:
                    if(i <= k) ans = min(ans, n / i);
                    if(n / i <= k) ans = min(ans, i);
                }
            }

            cout << ans << "\n";
        }
    }

    return 0;
}