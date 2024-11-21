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
        int a, b;
        cin >> a >> b;

        string sa, sb;
        cin >> sa;
        cin >> sb;

        vector<int> f1 (26);
        vector<int> f2 (26);
        for(auto i: sa) f1[i - 'a']++;
        for(auto i: sb) f2[i - 'a']++;

        bool poss = false;
        for(int i=0; i<26; i++) {
            if(f1[i] == 0 && f2[i] == 0) {
                poss = true;
                break;
            }
        }
        if(poss) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}