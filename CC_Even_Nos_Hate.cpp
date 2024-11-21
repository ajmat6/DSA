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
        int even = 0;
        int odd = 0;
        for(int i=0; i<n; i++) {
            cin >> nums[i];
            if(nums[i] % 2 == 0) even++;
            else odd++;
        }

        if(odd == 0) cout << "0\n";
        else {
            int ans = even + 1;
            odd -= 1;
            ans += odd / 2;
            cout << ans << "\n";
        }
    }

    return 0;
}