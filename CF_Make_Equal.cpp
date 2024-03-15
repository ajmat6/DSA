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

        vi water (n);
        ll sum = 0;
        for(int i=0; i<n; i++) {
            cin >> water[i];
            sum += water[i];
        }


        if(sum % n != 0) cout << "NO\n";
        else {
            int each = sum / n;
            int rem = 0;

            bool poss = true;
            for(int i=0; i<n; i++) {
                int total = water[i] + rem;
                if(total >= each) rem = total - each;
                else {
                    poss = false;
                    break;
                }
            }

            if(poss) cout << "YES\n";
            else cout << "NO\n";
        }

    }

    return 0;
}