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

        vi nums (n + 1);
        for(int i=0; i<=n; i++) cin >> nums[i];

        while(true) {
            int element = nums[n];
            int ansIndex = -1;
            int ans = INT_MIN;
            for(int i=0; i<n; i++) {
                if(nums[i] <= 2 * element) {
                    if(nums[i] > ans) {
                        ans = nums[i];
                        ansIndex = i;
                    }
                }
            }

            if(ansIndex == -1) break;
            if(ans <= element) break;
            else {
                swap(nums[n], nums[ansIndex]);
            }
        }

        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        cout << sum << endl;
    }

    return 0;
}