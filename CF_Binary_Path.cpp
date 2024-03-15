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

        string s1, s2;
        cin >> s1;
        cin >> s2;

        int i = 0;
        string ans = ""; ans += s1[0];
        int count = 1;
        while(true) {
            if(i == n-1) {
                ans.pb(s2[n-1]);
                break;
            }

            if(s1[i + 1] == s2[i]) {
                count++;
                ans.pb(s1[i + 1]);
            }

            else if(s1[i + 1] < s2[i]) {
                count = 1;
                ans.pb(s1[i + 1]);
            }

            else {
                for(int j=i; j<n; j++) ans.pb(s2[j]);
                break;
            }
            i++;
        }

        cout << ans << "\n" << count << "\n";
    }

    return 0;
}