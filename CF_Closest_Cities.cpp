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

        vll temp (n);
        for(int i=0; i<n; i++) cin >> temp[i];

        vi prefix (n);
        vi suffix (n);
        prefix[1] = 1;
        suffix[n-2] = 1;
        for(int i=1; i<n-1; i++) {
            if(abs(temp[i] - temp[i-1]) > abs(temp[i] - temp[i + 1])) prefix[i + 1] = prefix[i] + 1;
            else prefix[i + 1] = prefix[i] + abs(temp[i] - temp[i + 1]);
        }

        for(int i=n-2; i>0; i--) {
            if(abs(temp[i] - temp[i-1]) < abs(temp[i] - temp[i + 1])) suffix[i - 1] = suffix[i] + 1;
            else suffix[i - 1] = suffix[i] + abs(temp[i] - temp[i - 1]);
        }

        int m;
        cin >> m;

        for(int i=0; i<m; i++) {
            int s, d;
            cin >> s >> d;

            s -= 1;
            d -= 1;

            if(d > s) cout << prefix[d] - prefix[s] << "\n";
            else cout << suffix[d] - suffix[s] << "\n";
        }
    }

    return 0;
}