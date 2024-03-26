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
        ll n;
        cin >> n;

        vll nums (n);
        for(int i=0; i<n; i++) cin >> nums[i];

        vll temp;
        for(int i=0; i<n; i++) {
            if(nums[i] < i + 1) temp.pb(i + 1);
        }

        ll ans = 0;
        for(int i=1; i<temp.size(); i++) {
            ll element = nums[temp[i] - 1];
            int index = lower_bound(temp.begin(), temp.end(), element) - temp.begin();
            ans += index;
        }

        cout << ans << "\n";
    }

    return 0;
}