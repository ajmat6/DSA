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

        // we need max 2 coin of 1:
        // we need max 1 coin of 3:
        // we need max 4 coin of 6:
        // we need max 2 coin of 10:
        // and 15 are remaining:

        int ans = INT_MAX;
        for(int ones=0; ones<=2; ones++) {
            for(int three=0; three<=1; three++) {
                for(int six=0; six<=4; six++) {
                    for(int ten=0; ten<=2; ten++) {
                        int sum = ones * 1 + three * 3 + six * 6 + ten * 10;
                        if(sum <= n && ((n - sum) % 15) == 0) ans = min(ans, ones + three + six + ten + (n - sum) / 15);
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}