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
        int n;
        cin >> n;

        if(n % 2 == 0) cout << n / 2 << " " << n / 2 << "\n";
        else {
            // if the odd no is a prime no answer would be 1 and n - 1
            // else we have to find the largest no that divides n and for that we have to calculate the smallest prime no or simply a no that divides that no:
            bool found = false;
            for(int i=2; i*i<=n; i++) {
                // if i is a prime no then check if it divides n
                // if it does then n / i is the the largest no that divides n and hence, n / i and n - (n / i) are the two nos having smallest lcm
                if(n % i == 0) {
                    cout << n / i << " " << n - (n / i) << "\n";
                    found = true;
                    break;
                }
            }

            if(!found) cout << "1 " << n - 1 << "\n";
        }
    }

    return 0;
}