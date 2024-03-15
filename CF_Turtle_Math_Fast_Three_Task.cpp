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

        bool one = false;
        bool four = false;
        int sum = 0;
        vi temp(n);

        for(int i=0; i<n; i++) {
            cin >> temp[i];
            if(temp[i] == 1) one = true;
            if(temp[i] % 4 == 0) four = true;
            sum += temp[i];
        }

        if(sum % 3 == 0) cout << "0\n";
        else if(sum % 3 == 2) cout << "1\n";
        else {
            bool poss = false;
            for(int i=0; i<n; i++) {
                if(temp[i] % 3 == 1) {
                    poss = true;
                    break;
                }
            }

            if(poss) cout << "1\n";
            else cout << "2\n";
        }


    }

    return 0;
} 