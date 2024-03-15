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
        int p, t, x;
        cin >> p >> t >> x;

        set<int> st;
        st.insert(x);

        for(int i=0; i<t; i++) {
            int dis; char dir;
            cin >> dis >> dir;

            // all set players will throw dis distance in dir direction:
            vi temp (st.begin(), st.end());
            st.clear();

            for(int j=0; j<temp.size(); j++) {
                int player = temp[j];
                if(dir == '0') {
                    int pos = (player + dis) % p;
                    if(pos == 0) pos = p;
                    st.insert(pos);
                }
                else if(dir == '1') {
                    int pos = player - dis;
                    if(pos <= 0) pos += p;
                    st.insert(pos);
                }
                else {
                    int pos1 = (player + dis) % p;
                    if(pos1 == 0) pos1 = p;
                    st.insert(pos1);
                    int pos = player - dis;
                    if(pos <= 0) pos += p;
                    st.insert(pos);
                }
            }
        }

        vi ans (st.begin(), st.end());
        cout << ans.size() << "\n";
        for(auto i: ans) cout << i << " ";
        cout << "\n";
    }

    return 0;
}