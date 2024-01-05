#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<char, int> mp;
        int count = 0;

        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }

        if(mp.find('1') == mp.end())
        {
            cout << "YES\n";
            continue;
        }

        if(mp.find('0') == mp.end())
        {
            cout << "NO\n";
            continue;
        }

        for(int i=0; i<s.size()-1; i++)
        {
            if(s[i] != s[i+1]) count++;
        }

        if(count > 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}