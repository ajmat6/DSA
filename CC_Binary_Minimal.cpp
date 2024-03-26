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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int count = 0;
        for(auto i: s) {
            if(i == '1') count++;
        }

        if(k >= count) {
            // delete them:
            int size = n - count;
            string ans = "";
            ans.append(size, '0');
            cout << ans << "\n";
        }

        else {
            int i = 0;
            while(i < n & k > 0) {
                if(s[i] == '1') {
                    s[i] = '0';
                    k--;
                }
                i++;
            }   

            if(k != 0) {
                string temp = s.substr(0, n - k);
                cout << temp << "\n";
            }  
            else cout << s << "\n";   
        }
    }

    return 0;
}