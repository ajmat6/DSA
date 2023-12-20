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
        int n, k;
        cin >> n >> k;

        vector<int> ans;
        if(k == 0)
        {
            for(int i=n; i>=1; i--)
            {
                ans.pb(i);
            }
            
            for(auto i: ans) cout << i << " ";
        } 

        else
        {
            ans.pb(1);

            // first iteration:
            int start = n - k + 1;
            for(int i=start; i<=n; i++) ans.pb(i);

            // second iteration:
            int againStart = start - 1;
            for(int i=againStart; i>1; i--) ans.pb(i);

            for(auto i: ans) cout << i << " ";
        }       
    }

    return 0;
}