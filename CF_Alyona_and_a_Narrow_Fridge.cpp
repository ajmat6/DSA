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

    int n, h;
    cin >> n >> h;
    vi nums (n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int ans = 1;
    vi temp;
    for(int i=0; i<n; i++) {
        temp.pb(nums[i]);
        int j = 0; ll total = 0;
        sort(temp.rbegin(), temp.rend());
        while(j < temp.size()) {
            total += temp[j] * 2;
            j += 2;
        }
        if(total <= h * 2) ans = i + 1;
        else break;
    }

    cout << ans;

    return 0;
}