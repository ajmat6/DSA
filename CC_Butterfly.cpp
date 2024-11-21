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
        int r, g, b;
        cin >> r >> g >> b;

        // reduce in R, G, B:
        int R = r;
        int G = g;
        int B = b;

        if(G + B < r) {
            cout << "NO\n";
            continue;
        }
        else {
            if(G >= r) G -= r;
            else {
                r -= G;
                G = 0;
                B -= r;
            }
        }

        if(R + B < g) {
            cout << "NO\n";
            continue;
        }
        else {
            if(B >= g) B -= g;
            else {
                g -= B;
                B = 0;
                R -= g;
            }
        }

        if(R + G >= b) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}