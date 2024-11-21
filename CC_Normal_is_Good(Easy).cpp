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
        for(int i=0; i<n; i++) cin >> nums[i];
        
        ll ans = 0;
        int index = 1;
        ll count = 1;
        while(index < n) {
            if(nums[index] == nums[index - 1]) count++;
            else {
                ans += (count * (count + 1)) / 2;
                count = 1;
            }
            index++;
        }
        ans += (count * 1LL * (count + 1)) / 2;
        cout << ans << "\n";
    }

    return 0;
}