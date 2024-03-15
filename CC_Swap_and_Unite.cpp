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
        string s;
        cin >> s;

        unordered_map<char, int> mp;
        for(auto i: s) mp[i]++;
        
        int ans = INT_MAX;
        for(int i=0; i<26; i++) {
            char c = 'a' + i;
            if(mp.find(c) != mp.end()) {
                int freq = mp[c];
                int count = 0;
                for(int j=0; j<freq; j++) {
                    if(s[j] == c) count++;
                }

                int low = 0;
                int high = freq - 1;
                while(high < s.size()) {
                    ans = min(ans, freq - count);
                    if(s[low++] == c) count--;
                    if(high < s.size() - 1 && s[high + 1] == c) count++;
                    high++;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}