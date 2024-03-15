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

        int first = (s[0] == '1') ? 1 : 0;
        int i = 0;
        vi temp;
        while(i < s.size()) {
            int j = i;
            char c = (first == 0) ? '0' : '1';
            while(j < s.size() && s[j] == c) j++;
            int len = j - i;
            temp.pb(len);
            i = j;
            first = !first;
        }   

        ll mul = 1; ll op = 0;
        int size = temp.size();
        for(auto i: temp) mul = (mul * i) % 998244353;
        int del = s.size() - size;
        for(int i=1; i<=del; i++) mul = (mul * i) % 998244353;
        cout << del << " " << mul << "\n";        
    }

    return 0;
}