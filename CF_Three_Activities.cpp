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
        int days;
        cin >> days;

        vector<long> s (days);
        vector<long> m (days);
        vector<long> b (days);

        for(int i=0; i<days; i++) cin >> s[i];
        for(int i=0; i<days; i++) cin >> m[i];
        for(int i=0; i<days; i++) cin >> b[i];

        vector<pll> temp;
        for(int i=0; i<days; i++) temp.pb({s[i], i + 1});
        for(int i=0; i<days; i++) temp.pb({m[i], i + 1});
        for(int i=0; i<days; i++) temp.pb({b[i], i + 1}); 

        sort(temp.begin(), temp.end());

        set<int> st;
        int ans = 0;
        int count = 0;
        for(auto i: temp)
        {
            int score = i.first;
            int day = i.second;

            if(st.find(day) == st.end())
            {
                ans += score;
                count++;
                if(count == 3) break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}