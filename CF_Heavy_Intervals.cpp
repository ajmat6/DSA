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

bool cmp(int a, int b) {
    return a > b;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    return a.first <= b.first;
}

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

        vll l (n);
        vll r (n);
        vll c (n);

        vector<pll> pairs;
        for(int i=0; i<n; i++) {
            cin >> l[i];
            pairs.pb({l[i], -1});
        }

        for(int i=0; i<n; i++) {
            cin >> r[i];
            pairs.pb({r[i], -2});
        } 

        for(int i=0; i<n; i++) cin >> c[i];

        sort(pairs.begin(), pairs.end(), cmp2);
        sort(c.begin(), c.end(), cmp);

        stack<pair<int, int>> st;
        vll temp;
        for(auto &i: pairs) {
            if(i.second == -1) st.push(i);
            else {
                ll lValue = st.top().first; st.pop();
                ll rValue = i.first;
                temp.pb(rValue - lValue);
            }
        }

        sort(temp.begin(), temp.end());

        ll ans = 0;
        for(int i=0; i<n; i++) {
            ans += temp[i] * c[i];
        }

        cout << ans << "\n";
    }

    return 0;
}