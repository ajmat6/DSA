#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;

void check(set<pair<int, int>>& st, int qx, int qy, int& ans, int a, int b)
{
    for(auto i: st)
    {
        int x = i.first;
        int y = i.second;

        int pointX = abs(qx - x);
        int pointY = abs(qy - y);

        if((pointX == a && pointY == b) || (pointX == b && pointY == a)) ans++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int a, b;
        cin >> a >> b;
        int kx, ky;
        cin >> kx >> ky;
        int qx, qy;
        cin >> qx >> qy;

        set<pair<int, int>> st;
        st.insert({kx + a, ky + b});
        st.insert({kx - a, ky - b});
        st.insert({kx - a, ky + b});
        st.insert({kx + a, ky - b});
        st.insert({kx + b, ky + a});
        st.insert({kx - b, ky - a});
        st.insert({kx - b, ky + a});
        st.insert({kx + b, ky - a});

        int ans = 0;
        check(st, qx, qy, ans, a, b);
        cout << ans << "\n";
    }

    return 0;
}   