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
        int len, total;
        cin >> len >> total;

        vector<string> nums;
        for(int i=0; i<total; i++) {
            string s;
            cin >> s;
            nums.pb(s);
        }

        unordered_map<int, pair<int, int>> mp;
        for(int i=0; i<len; i++) {
            int ones = 0;
            int zero = 0;
            for(int j=0; j<total; j++) {
                if(nums[j][i] == '0') zero++;
                else if(nums[j][i] == '1') ones++;
            }
            mp[i] = make_pair(zero, ones);
        }

        ll ans = 0;
        for(auto i: mp) {
            int zero = i.second.first;
            int ones = i.second.second;

            int totalHere = zero + ones;
            if(totalHere != total) {
                int rem = total - totalHere;
                if(rem == total) {
                    ones++;
                    zero++;
                    rem -= 2;
                }

                while(rem != 0) {
                    if((ones + 1) * 1LL * zero >= ones * 1LL * (zero + 1)) ones += 1;
                    else zero += 1;
                    rem -= 1;
                }
            }

            ans += (zero * 1LL * ones);
        }

        cout << ans << "\n";
    }

    return 0;
}