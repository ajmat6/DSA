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
        ll a, b;
        cin >> a >> b;

        ll diff = abs(a - b);

        // smallest n for which sum of n as ap is >= diff:
        ll low = 1;
        ll high = 1e9;
        ll n = high;

        while(low <= high) {
            ll mid = low + (high - low) / 2;

            ll sum = mid * (mid + 1) / 2;
            if(sum >= diff) {
                n = min(n, mid);
                high = mid - 1;
            }

            else low = mid + 1;
        }

        ll sum = n * (n + 1) / 2;
        if(sum == diff) {
            cout << n << "\n";
        }

        else {
            int evenCheck = sum - diff;
            if(evenCheck % 2 == 0) cout << n << "\n";
            else {
                n++;
                sum += n;
                evenCheck = sum - diff;
                if(evenCheck % 2 == 0) cout << n << "\n";
                else {
                    cout << n + 1 << "\n";
                }
            }
        }
    }

    return 0;
}