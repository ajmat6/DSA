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

        vi a (n);
        for(int i=0; i<n; i++) cin >> a[i];

        int low = 0;
        while(low < n && a[low] == a[0]) low++;
        int left;
        if(low == n) left = 0;
        else left = (n - 1) - low + 1;

        int high = n - 1;
        while(high >= 0 && a[high] == a[n - 1]) high--;
        int right;
        if(high < 0) right = 0;
        else right = high - 0 + 1;

        if(a[0] == a[n - 1]) {
            int low = 0;
            int high = n - 1;

            while(low < n && a[low] == a[0]) low++;
            while(high >= 0 && a[high] == a[0]) high--;

            int both;
            if(low > high) both = 0;
            else both = high - low + 1;

            cout << min(both, min(left, right)) << "\n";
        }


        else cout << min(left, right) << "\n";
    }

    return 0;
}