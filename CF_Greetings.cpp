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

        vector<vector<int>> t (n, vi (2));
        for(int i=0; i<n; i++)
        {
            cin >> t[i][0] >> t[i][1];
        }     

        vpii temp;
        for(int i=0; i<n; i++)
        {
            temp.push_back({t[i][0], t[i][1]});
        }

        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());

        int ans = 0;
        ordered_set<int> st;
        for(auto i: temp)
        {
            ans += st.size() - order_of_key(i.S);
            st.insert(i.F);
        }

        cout << ans << "\n";
    }

    return 0;
}