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

        if(n <= 28) {
            char ch = 'a' + (n - 2 - 1);
            string ans = "aa";
            ans.pb(ch);
            cout << ans << "\n";
        }

        else if(n <= 53) {
            string ans = "a";
            char ch = 'a' + (n - 26 - 1 - 1);
            ans.pb(ch);
            ans.pb('z');
            cout << ans << "\n";
        }

        else {
            char ch = 'a' + (n - 52 - 1);
            string ans = "";
            ans.pb(ch);
            ans += "zz";
            cout << ans << "\n";
        }
    }

    return 0;
}