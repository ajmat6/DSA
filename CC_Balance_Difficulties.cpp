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

bool check(vll& temp, ll val, ll x) {
    ll prev = temp[0] + val;

    for(int i=1; i<temp.size(); i++) {
        if(temp[i] - prev <= x) {
            ll currDiff = temp[i] - prev;
            ll canMove = x - currDiff;
            ll moveWith = min(canMove, val);
            prev = temp[i] + moveWith;
        }
        
        else {
            ll diff = temp[i] - prev;
            ll need = x;
            ll move = min(val, diff - need);
            ll lastPrev = prev;
            prev = temp[i] - move;
            if(prev - lastPrev > x) return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        ll n, x;
        cin >> n >> x;

        vll nums (n);
        for(int i=0; i<n; i++) cin >> nums[i];

        if(n == 1) {
            cout << "0\n";
            cout << nums[0] << "\n";
        }

        else {
            ll low = 0;
            ll high = 2 * 1e9;

            ll ans = high;
            while(low <= high) {
                ll mid = low + (high - low) / 2;
                if(check(nums, mid, x)) {
                    ans = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            
            nums[0] += ans;
            for(int i=1; i<nums.size(); i++) {
                nums[i] = min(nums[i] + ans, nums[i - 1] + x);
            }

            cout << ans << "\n";
            for(auto i: nums) cout << i << " ";
            cout << "\n";
        }
    }

    return 0;
}