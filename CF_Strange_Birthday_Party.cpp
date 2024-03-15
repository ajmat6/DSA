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
typedef vector<pll> vpll;
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
        ll n, m;
        cin >> n >> m;

        vll nums (n);
        vll cost (m);

        for(ll i=0; i<n; i++) cin >> nums[i];
        for(ll i=0; i<m; i++) cin >> cost[i];

        int low = 0; ll ans = 0;
        sort(nums.rbegin(), nums.rend());
        for(int i=0; i<nums.size(); i++) {
            ll index = nums[i] - 1;
            ll money = cost[index];
            ll cheap = cost[low];

            if(cheap < money) {
                ans += cheap;
                low++;
            }

            else ans += money;
        }

        cout << ans << "\n";
    }

    return 0;
}