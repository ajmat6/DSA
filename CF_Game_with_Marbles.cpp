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

bool compare(vll& a, vll& b) {
    return a[0] > b[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vll a (n);
        vll b (n);

        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        vector<vll> temp (n, vll (3));
        for(int i=0; i<n; i++) {
            temp.pb({a[i] + b[i], a[i], b[i]});
        }

        sort(temp.begin(), temp.end(), compare);

        ll A = 0;
        ll B = 0;
        int turn = 1;
        for(int i=0; i<n; i++) {
            if(turn == 1) {
                A += temp[i][1] - 1;
                turn = 0;
            }
            else {
                B += temp[i][2] - 1;
                turn = 1;
            } 
        }

        cout << A - B << "\n";
    }

    return 0;
}