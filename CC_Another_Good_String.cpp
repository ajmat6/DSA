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
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        int low = 0;
        int high = 1;
        int longest = 1;
        while(high < n) {
            if(s[high] == s[low]) high++;
            else {
                longest = max(longest, high - low);
                low = high;
                high++;
            }
        }

        longest = max(longest, high - low);
        vector<int> ans;
        ans.pb(longest);

        char prev = s[low];
        int count = high - low;
        for(int i=0; i<q; i++) {
            char c;
            cin >> c;

            if(c == prev) {
                longest = max(longest, count + 1);
                count++;
            }

            else {
                prev = c;
                count = 1;
                longest = max(longest, count);
            }

            ans.pb(longest);
        }

        for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}