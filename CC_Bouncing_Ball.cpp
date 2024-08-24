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

        vi nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];

        vll prefix (n); prefix[0] = nums[0];
        vll suffix (n); suffix[n-1] = nums[n-1];

        for(int i=1; i<n; i++) prefix[i] = nums[i] + prefix[i - 1];
        for(int i=n-2; i>=0; i--) suffix[i] = nums[i] + suffix[i + 1];

        ll ans = 0;
        for(int i=1; i<n-1; i++) {
            if(nums[i] == 0) {
                if(prefix[i - 1] == suffix[i + 1]) ans += 2;
                else if(abs(prefix[i - 1] - suffix[i + 1]) == 1) ans += 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}