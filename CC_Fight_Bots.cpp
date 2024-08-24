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
        int n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;

        vpii points;
        int row = 0;
        int col = 0;
        for(auto i: s) {
            if(i == 'U') col++;
            else if(i == 'D') col--;
            else if(i == 'R') row++;
            else row--;

            points.push_back({row, col});
        }

        int attempt = 1;
        bool poss = false;
        for(auto i: points) {
            int xp = i.first;
            int yp = i.second;

            int dis = abs(x - xp) + abs(y - yp);
            if(dis == attempt) {
                poss = true;
                break;
            }
            else attempt++;
        }

        if(poss) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}