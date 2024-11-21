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
        int ones = 0;
        for(int i=0; i<n; i++) {
            cin >> nums[i];
            if(nums[i]) ones++;
        }


        ll prev = 0;
        ll ans = 0;
        for(int i=1; i<n; i++) {
            if(nums[i] == 1 && nums[i - 1] == 1) {
                ll left = i - prev;
                ll right = n - i;
                ans += (left * right);
                prev = i;
            }
            else if(i >= 2 && nums[i] == 1 && nums[i - 1] == 0 && nums[i - 2] == 1) {
                ll left = i - prev - 1;
                ll right = n - i;
                ans += (left * right);
                prev = i - 1;
            }
        }

        cout << ans + ones << "\n"; // ones for single ones as winning subarray case
    }

    return 0;
}