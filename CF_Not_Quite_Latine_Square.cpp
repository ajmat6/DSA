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
        string a, b, c;
        cin >> a >> b >> c;

        set<char> st;
        if(a[0] == '?' || a[1] == '?' || a[2] == '?')
        {
            st.insert(a[0]);
            st.insert(a[1]);
            st.insert(a[2]);

            if(st.find('A') == st.end()) cout << "A\n";
            else if(st.find('B') == st.end()) cout << "B\n";
            else cout << "C\n";
        }
        else if(b[0] == '?' || b[1] == '?' || b[2] == '?')
        {
            st.insert(b[0]);
            st.insert(b[1]);
            st.insert(b[2]);

            if(st.find('A') == st.end()) cout << "A\n";
            else if(st.find('B') == st.end()) cout << "B\n";
            else cout << "C\n";
        }
        else
        {
            st.insert(c[0]);
            st.insert(c[1]);
            st.insert(c[2]);

            if(st.find('A') == st.end()) cout << "A\n";
            else if(st.find('B') == st.end()) cout << "B\n";
            else cout << "C\n";
        }
    }

    return 0;
}