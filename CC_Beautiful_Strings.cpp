#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
const int mod = 1000000007;
int ans = 0;
unordered_map<string, int> mp;

void solve(string& s, int n, int index, string temp)
{
    if(index == n)
    {
       string st = temp;
       sort(st.begin(), st.end());
       if(st == temp && mp.find(st) == mp.end()) 
       {
            ans++;
            mp[temp]++;
            cout << temp << endl;
       } 
       return;
    }

    for(int i=index; i<n; i++)
    {
        solve(s, n, index + 1, temp + s[index]);
        solve(s, n, index + 1, temp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        solve(s, n, 0, "");
        cout << ans;
        ans = 0;
        mp.clear();
        cout << "\n";
    }
    

    return 0;
}