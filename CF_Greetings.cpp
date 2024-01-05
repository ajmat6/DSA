#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
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
        ll n;
        cin >> n;

        vector<vll> t (n, vll (2));
        for(ll i=0; i<n; i++)
        {
            cin >> t[i][0] >> t[i][1];
        }     

        vector<pll> temp;
        for(ll i=0; i<n; i++)
        {
            temp.push_back({t[i][0], t[i][1]});
        }

        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());

        ll ans = 0;
        ordered_set st;
        st.clear();
        for(auto i: temp)
        {
            ans += st.order_of_key(i.S);
            st.insert(i.S);
        }

        cout << ans << "\n";
    }

    return 0;
}