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
        int n, q;
        cin >> n >> q;

        vi temp (n);
        ll sum = 0;
        for(int i=0; i<n; i++) {
            cin >> temp[i];
            sum += temp[i];
        }

        sort(temp.begin(), temp.end());
        for(int k=0; k<q; k++) {
            int x;
            cin >> x;
            bool found = false;
            for(int i=0; i<n; i++) {
                for(int j=i+1; j<n; j++) {
                    int currSum = sum - temp[i] - temp[j];
                    currSum += currSum;
                    currSum += temp[i] + temp[j];

                    // is taking these two indexes as first and last, is currSum equals to sum x:
                    if(currSum == x) {
                        cout << temp[i] << " ";
                        for(int index=0; index<n; index++) {
                            if(index == i || index == j) continue;
                            else cout << temp[index] << " ";
                        }
                        cout << temp[j] << "\n";
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            if(!found) cout << "-1\n";
        }
    }

    return 0;
}


// 2nd approach -> your in contest
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
        int n, q;
        cin >> n >> q;

        vi temp (n);
        for(int i=0; i<n; i++) cin >> temp[i];

        sort(temp.begin(), temp.end());
        unordered_map<ll, vll> mp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                vll t;
                ll sum = temp[i] + temp[j];
                t.pb(temp[i]);
                for(int k=0; k<n; k++) {
                    if(k != i && k != j) {
                        t.pb(temp[k]);
                        sum += temp[k] + temp[k];
                    }
                }

                t.pb(temp[j]);
                mp[sum] = t;
            }
        }

        for(int i=0; i<q; i++) {
            ll sum;
            cin >> sum;
            
            if(mp.find(sum) != mp.end()) {
                vll ans = mp[sum];
                for(int i=0; i<n; i++) cout << ans[i] << " ";
                cout << "\n";
            }
            else cout << "-1\n";
        }
    }

    return 0;
}