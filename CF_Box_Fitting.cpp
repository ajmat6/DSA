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
        int n, w;
        cin >> n >> w;

        vi nums (n);
        for(int i=0; i<n; i++) cin >> nums[i];

        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size() - 1;

        ll ans = 0;
        while(low <= high) {
            ll count = 0;
            while(high >= low && count + nums[high] <= w) {
                count += nums[high];
                high--;
            }

            while(low <= high && count + nums[low] <= w) {
                count += nums[low];
                low++;
            }

            ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}