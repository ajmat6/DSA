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

bool cmp(int &a, int &b) {
    return a >= b;
}

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

        vi temp (n);
        map<int, int> mp;
        for(int i=0; i<n; i++) {
            cin >> temp[i];
            mp[temp[i]]++;
        }

        vi v;
        int mini = INT_MAX;
        int value = 0;
        for(auto i: mp) {
            if(i.first < mini) {
                mini = i.first;
                value = i.second;
            }
            v.pb(i.first);
        }

        if(value == 1) cout << "YES\n";
        else {
            if(v.size() == 1 and n > 1) cout << "NO\n";
            else {
                bool poss = false;
                for(int i=1; i<v.size(); i++) {
                    int rem = v[i] % mini;
                    if(rem != 0 && rem < mini) {
                        poss = true;
                        break;
                    }
                }

                if(poss) cout << "YES\n";
                else cout << "NO\n";
            }
        }

    }

    return 0;
}