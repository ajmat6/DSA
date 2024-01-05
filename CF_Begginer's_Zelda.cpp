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

    ll t;
    cin >> t;

    while(t--)
    {
        ll nodes;
        cin >> nodes;

        unordered_map<ll, list<ll>> mp;
        for(ll i=0; i<(nodes - 1); i++)
        {
            ll a, b;
            cin >> a >> b;
            mp[a].pb(b);
        }

        // iterate over map and count ans:
        ll ans = 0;
        set<ll> st;
        for(auto i: mp)
        {
            ll sizee = i.second.size();
            
            if(st.find(i.first) == st.end())
            {
                if(sizee >= 2) ans += (sizee - 1);
            }
            
            else
            {
                if(sizee > 2) ans += (sizee - 2);
            }

            for(auto j: i.second) st.insert(j);
        }

        cout << ans << "\n";
    }

    return 0;
}