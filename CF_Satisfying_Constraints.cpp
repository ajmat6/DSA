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

    while(t--) {
        int n;
        cin >> n;

        vector<pll> temp;
        for(int i=0; i<n; i++) {
            ll a, b;
            cin >> a >> b;
            temp.pb({a, b});
        }

        ll low = INT_MIN;
        ll high = INT_MAX;
        set<int> st;

        for(int i=0; i<temp.size(); i++) {
            int type = temp[i].F;
            int value = temp[i].S;

            if(type == 1) {
                if(value >= low) low = value;
            }

            else if(type == 2) {
                if(value <= high) high = value;
            }

            else st.insert(value);
        }

        if(low > high) cout << "0\n";
        else
        {
            ll count = high - low + 1;
            for(auto i: st)
            {
                if(i >= low && i <= high) count--;
            }
            cout << count << "\n";
        }
    }

    return 0;
}