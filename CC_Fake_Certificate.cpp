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

        int count = 0;
        for(auto i: s) {
            if(i == '1') count++;
        }

        int i = 0; int ans = INT_MIN;
        while(i < n) {
            int j = i;
            if(s[j] == '0') {
                while(j < n && s[j] == '0') j++;
                int k = j;
                while(k < n && s[k] == '1') k++;
                int ones = k - j;
                ans = max(ans, k - i + (count - ones));
                i = j;
            }

            else {
                while(j < n && s[j] == '1') j++;
                int ones = j - i;
                while(j < n && s[j] == '0') j++;
                int k = j;
                while(k < n && s[k] == '1') k++;
                ones += k - j;
                ans = max(ans, k - i + (count - ones));
                i = j;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}