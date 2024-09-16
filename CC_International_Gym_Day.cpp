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
        int d, x, y;
        cin >> d >> x >> y;

        if(x <= y) {
            cout << "0\n";
            continue;
        }

        int trials = 1;
        bool found = false;
        while(trials <= y) {
            int discount = d * trials;
            int coinsLeft = y - trials;
            int costPercent = 100 - discount;
            int cost = ceil((double)(costPercent * x) / 100);
            if(cost <= coinsLeft) {
                cout << trials << "\n";
                found = true;
                break;
            }
            else trials++;
        }

        if(!found) cout << "-1\n";
    }

    return 0;
}