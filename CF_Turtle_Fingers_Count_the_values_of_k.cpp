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
        int a, b, l;
        cin >> a >> b >> l;

        // if l % (a^x * b^y) == 0, then insert in set for avoiding duplicacy;
        set<int> st;
        for(int x=0; pow(a, x) <= l; x++) {
            int first = pow(a, x);
            for(int y=0; pow(b, y) * first <= l; y++) {
                int second = pow(b, y);
                if(l % (first * second) == 0) st.insert(l / (first * second));
            }
        }

        cout << st.size() << "\n";
    }

    return 0;
}