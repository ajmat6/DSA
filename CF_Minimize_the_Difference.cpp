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

bool check1(vll nums, ll mid) {
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] > mid) {
            if(i != nums.size() - 1) nums[i + 1] += nums[i] - mid;
            else return false;
        }
    }
    return true;
}

bool check2(vll nums, ll mid) {
    for(int i=nums.size()-1; i>=0; i--) {
        if(nums[i] < mid) {
            if(i != 0) nums[i - 1] -= mid - nums[i];
            else return false;
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
        int n;
        cin >> n;

        vll nums(n);
        ll mini = LLONG_MAX;
        ll maxi = LLONG_MIN;
        for(int i=0; i<n; i++) {
            cin >> nums[i];
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        // finding how much you can minimize the maximum number:
        ll low = mini;
        ll high = maxi - 1;
        ll ans1 = maxi;
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            if(check1(nums, mid)) {
                ans1 = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        // finding how much you can maximize the minimum number:
        low = mini + 1;
        high = maxi;
        ll ans2 = mini;
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            if(check2(nums, mid)) {
                ans2 = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }

        cout << ans1 - ans2 << "\n";
    }

    return 0;
}