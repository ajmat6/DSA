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

        int ans = 0;
        for(int i=0; i<n-2; i++) {
            string temp = "";
            temp += s[i];
            temp += s[i + 1];
            temp += s[i + 2];
            if(temp == "map" || temp == "pie") {
                ans++;
                i += 2;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}