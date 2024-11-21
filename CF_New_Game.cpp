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

        vll nums (n);
        for(ll i=0; i<n; i++) cin >> nums[i];

        sort(nums.begin(), nums.end());
        ll low = 0, high = 1, sum = 1, count = 1, ans = 1;
        while(high < n) {
            if(nums[high] == nums[high - 1] || nums[high] == nums[high - 1] + 1) {
                sum += 1;
                if(nums[high] != nums[high - 1]) count += 1;
            }
            else {
                sum = 1;
                low = high;
                count = 1;
            }

            if(count > k) {
                ll lowVal = nums[low];
                while(nums[low] == lowVal) {
                    low++;
                    sum--;
                }
                count -= 1;
            }

            ans = max(ans, sum);
            high++;
        }

        cout << ans << "\n";
    }

    return 0;
}