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

bool cmp(ll a, ll b) {
    return a >= b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--) {
        ll n, k, x;
        cin >> n >> k >> x;

        vll a(n);
        ll sum = 0;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end(), cmp);
        ll firstXSum = 0;
        for(int i=0; i<x; i++) {
            if(i < n) firstXSum += a[i];
        }

        ll rem = sum - firstXSum; // when 0 elements are removed:
        ll ans = rem - firstXSum;

        ll lower = 0; ll higher = x;
        for(ll i=0; i<k; i++) {
            if(higher < n) {
                firstXSum = firstXSum - a[lower] + a[higher];
                rem = rem - a[higher];
                ans = max(ans, rem - firstXSum);
                lower++;
                higher++;
            } 

            else if(lower < n) {
                firstXSum = firstXSum - a[lower];
                ans = max(ans, rem - firstXSum);
                lower++;
            }

            else break;
        }

        cout << ans << "\n";
    }

    return 0;
}