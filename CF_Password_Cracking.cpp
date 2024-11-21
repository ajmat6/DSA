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

int query(string temp) {
    cout << "? " << temp << "\n";
    int res;
    cin >> res;
    cout.flush();
    return res;
}

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

        string ans = "";
        for(int i=0; i<2*n; i++) {
            string temp = ans;
            if(ans.size() < n) {
                temp += '0';
            }

            int res = query(temp);
            if(res == 1) break;
            if(res == -1) break;
            if(ans.size() < n) ans += '1';
        }

        cout << "! " << ans << "\n";
    }

    return 0;
}