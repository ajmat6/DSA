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

        sort(nums.rbegin(), nums.rend());
        int l = nums[0];
        int s = nums[n-1];
        int sl = nums[1];
        int sm = nums[n - 2];

        cout << abs(l - s) + abs(s - sl) + abs(sl - sm) + abs(sm - l) << "\n";
    }

    return 0;
}