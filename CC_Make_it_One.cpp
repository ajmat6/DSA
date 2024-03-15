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
        int l, r;
        cin >> l >> r;

        if(l % 2 == 0 && r % 2 == 0) cout << "-1\n"; // start even end even
        else {
            vi temp;
            for(int i=l; i<=r; i++) temp.pb(i);
            for(int i=0; i<temp.size(); i+=2) {
                swap(temp[i], temp[i + 1]);
                if(l % 2 == 1 && r % 2 == 1 && i == temp.size() - 3) break; 
            }

            // start is odd and end is odd case: we have to swap last with third last:
            if(l % 2 == 1 && r % 2 == 1) {
                swap(temp[temp.size()-1], temp[temp.size()-3]);
            }

            for(auto i: temp) cout << i << " ";
            cout << "\n";
        }
    }

    return 0;
}