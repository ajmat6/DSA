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

        vi in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        // storing prev index for curr index at which the value is diff from curr value:
        vi prev(n); prev[0] = -1;
        for(int i=1; i<n; i++) {
            if(in[i] != in[i - 1]) prev[i] = i - 1;
            else prev[i] = prev[i - 1];
        }

        int q;
        cin >> q;
        while(q--) {
            int l, r;
            cin >> l >> r;

            if(prev[l-1] == prev[r-1]) cout << "-1 -1\n";
            else cout << r << " " << prev[r - 1] + 1 << "\n";
        }
    }

    return 0;
}