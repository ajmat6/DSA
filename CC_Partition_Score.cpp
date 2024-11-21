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
        int n, k;
        cin >> n >> k;

        vi nums (n);
        for(int i=0; i<n; i++) cin >> nums[i];

        sort(nums.begin(), nums.end());
        if(k == 1) cout << nums[n - 1] + nums[n - 1] + nums[n - 2] + nums[0] << "\n";
        else {
            ll ans = nums[n - 1] + nums[n - 2] + nums[0];
            k--;
            for(int i=n-3; i>=1; i--) {
                k--;
                if(k == 0) {
                    ans += nums[i];
                    break;
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}