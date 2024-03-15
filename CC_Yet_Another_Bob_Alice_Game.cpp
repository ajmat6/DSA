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
        int stones, alice, bob;
        cin >> stones >> alice >> bob;

        if(alice >= stones) cout << "Alice\n";
        else {
            if(alice > bob) cout << "Alice\n";
            else if(bob > alice) cout << "Bob\n";
            else {
                if(stones % (alice + 1) == 0) cout << "Bob\n";
                else cout << "Alice\n";
            }
        }
    }

    return 0;
}