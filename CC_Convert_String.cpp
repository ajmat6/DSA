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
        string s;
        cin >> s;

        int ones = 0;
        int zero = 0;
        for(auto i: s) {
            if(i == '0') zero++;
            else ones++;
        }

        if(ones == 0 || zero == 0) {
            int count = (ones == 0)? zero : ones;
            if(count % 2 == 0) cout << count / 2 << "\n";
            else cout << count / 2 + 1 << "\n";
        }

        else {
            bool odd = ones % 2 == 1 ? true : zero % 2 == 1 ? true : false;
            bool even = ones % 2 == 0 ? true: zero % 2 == 0 ? true : false;
            
            int mini = min(ones, zero);
            if(odd && even) {
                int ans = 1;
                int curr = mini + 1;
                int next = (mini == ones) ? zero : ones;
                while(curr != next) {
                    int rem = curr - mini;
                    if(rem % 2 == 0) ans++;
                    curr += 1;
                }
                
                ans += n - next + 1;
                cout << ans << "\n";
            }
            
            else if (odd) {
                int count = n - mini + 1;
                cout << count / 2 << endl;
            }
            
            else {
                int count = n - mini + 1;
                cout << count / 2 + 1 << endl;
            }
        }

    }

    return 0;
}