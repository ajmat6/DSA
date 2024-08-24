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
        int n, d;
        cin >> n >> d;
        vector<int> nums (n);
        for(int i=0; i<n; i++) cin >> nums[i];

        // 0 is close and 1 is far:
        int turn = 0; int ans = 0;
        for(auto i: nums) {
            if(i <= d && turn == 1) {
                ans += 1;
                turn = 0;
            }
            else if(i > d && turn == 0) {
                turn = 1;
                ans += 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}