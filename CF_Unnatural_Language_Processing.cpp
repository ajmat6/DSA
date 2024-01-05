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

    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int i = 0;
        string ans = "";
        while(i < n)
        {
            if(i == n - 2 || i == n - 3)
            {
                if(i == n - 2) ans += s.substr(i, 2);
                else ans += s.substr(i, 3);
                break;
            }

            else
            {
                if((s[i + 2] == 'b' || s[i + 2] == 'c' || s[i + 2] == 'd') && (s[i + 3] == 'b' || s[i + 3] == 'c' || s[i + 3] == 'd'))
                {
                    ans += s.substr(i, 3);
                    ans.pb('.');
                    i += 3;
                }

                else 
                {
                    ans += s.substr(i, 2);
                    ans.pb('.');
                    i += 2;
                }
            }
        }
        
        cout << ans << "\n";
    }


    return 0;
}