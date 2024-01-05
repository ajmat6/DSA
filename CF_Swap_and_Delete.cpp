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
        string s;
        cin >> s;
 
        // the string that I want:
        string t = "";
        unordered_map<char, int> mp;
        for(auto i: s)
        {
            if(i == '1') t += '0';
            else t += '1';
            mp[i]++;
        }
 
        // check for the strings:
        int i;
        for(i=0; i<t.size(); i++)
        {
            char ch = t[i];
            if(mp[ch] > 0) mp[ch]--;
            else break;
        }
 
        cout << t.size() - i << "\n";
    }
    return 0;
}