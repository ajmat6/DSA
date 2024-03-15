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
        ll k, x;
        cin >> k >> x;

        ll low = 1; ll high = (2 * k )- 1;
        while(low < high) {
            ll mid = low + (high - low) / 2;
            ll sum;
            if(mid <= k) sum = mid * (mid + 1) / 2;
            else {
                ll tillK = k * (k + 1) / 2;
                ll rem = k * (k - 1) / 2;
                ll minCount = (2 * k) - 1 - mid;
                ll minusSum = minCount * (minCount + 1) / 2;
                sum = tillK + (rem - minusSum);
            }

            if(sum < x) low = mid + 1;
            else high = mid;
        }

        cout << low << "\n";
    }

    return 0;
}