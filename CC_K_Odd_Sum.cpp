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

        vi even; vi odd;
        int e = 2; int o = 1;

        while(e <= n) {
            even.pb(e);
            e += 2;
        }

        while(o <= n) {
            odd.pb(o);
            o += 2;
        }

        int i = 1; int j = 0;
        vi ans; ans.pb(2);
        int curr = 0; // 0 is even and 1 is odd
        while(k != 1) {
            if(curr == 1) {
                if(i < even.size()) {
                    ans.pb(even[i]);
                    i++;
                    k--;
                    curr = 0;
                }
                else break;   
            }

            else {
                if(j < odd.size()) {
                    ans.pb(odd[j]);
                    j++;
                    k--;
                    curr = 1;
                }
                else break;
            }
        }

        if(curr == 0) {
            while(i < even.size()) {
                ans.pb(even[i]);
                i++;
            }

            while(j < odd.size()) {
                ans.pb(odd[j]);
                j++;
            }
        }

        else {
            while(j < odd.size()) {
                ans.pb(odd[j]);
                j++;
            }

            while(i < even.size()) {
                ans.pb(even[i]);
                i++;
            }
        }

        for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}