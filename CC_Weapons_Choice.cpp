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
        ll h, x, y1, y2, k;
        cin >> h >> x >> y1 >> y2 >> k;

        ll gun = h / x;
        if(h % x != 0) gun++;

        ll time = 0;
        ll sum = 0;
        ll count = 0;
        while(true) {
            if(time < k) {
                sum += y1;
                count++;
                time++;
                if(sum >= h) break;
            }

            else {
                int rem = h - sum;
                int count2 = rem / y2;
                if(rem % y2 != 0) count2++;
                count += count2;
                break;
            }
        }

        if(count <= gun) cout << count << "\n";
        else cout << gun << "\n";

    }

    return 0;
}