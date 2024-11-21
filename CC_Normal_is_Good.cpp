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

        vi nums (n);
        for(int i=0; i<n; i++) {
            cin >> nums[i];
            nums[i] -= 2;
        }

        map<ll, ll> mp; mp[0] = 1; // subarray sum equal 0 ques
        ll ans = 0; ll sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            ans += mp[sum]; // all subarray where 1's == 3's
            mp[sum]++;
        }
        
        mp.clear(); mp[0] = 1; sum = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                mp.clear(); mp[0] = 1; sum = 0;
                continue;
            }
            
            sum += nums[i];
            ans -= mp[sum]; // minus those subarrays with equal 1's and 3's and 0 2's
            mp[sum]++;
        }
        
        int index = 0;
        while(index < n) {
            if(nums[index] == 0) { // 2 wala case already included in first loop 
                index++;
                continue;
            }
            ll count = 1; index++;
            while(index < n && nums[index] == nums[index - 1]) {
                count++;
                index++;
            }
            ans += (count * 1LL * (count + 1) / 2);
        }
        
        cout << ans << "\n";
    }

    return 0;
}