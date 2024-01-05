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

        vll g (n);
        for(ll i=0; i<n; i++) cin >> g[i];

        for(ll i=0; i<n; i++)
        {
            if(i % 2 == 0) g[i] = -g[i];
        }

        // run a prefix sum and see any sub ka prefix sum do not add any contribution in the sum:
        set<ll> st;
        st.insert(g[0]);
        st.insert(0);
        bool poss = false;
        for(ll i=1; i<n; i++)
        {
            g[i] += g[i - 1];
            if(st.find(g[i]) == st.end()) st.insert(g[i]);
            else 
            {
                poss = true;
                break;
            }
        }

        if(poss) cout << "YES\n";
        else cout << "NO\n";
        
    }

    return 0;
}