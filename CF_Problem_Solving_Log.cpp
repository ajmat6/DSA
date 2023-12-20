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

    while(t--)
    {
        int min;
        cin >> min;

        string temp;
        cin >> temp;

        unordered_map<char, int> mp;
        char a = 'A';
        for(int i=1; i<=26; i++)
        {
            mp[a] = i;
            a++;
        }

        for(auto i: temp)
        {
            if(mp[i] > 0) mp[i]--;
        }

        int ans = 0;
        for(auto i: mp)
        {
            if(i.second == 0) ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}