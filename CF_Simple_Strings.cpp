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

    string s;
    cin >> s;

    int i = 0;
    int n = s.size();
    while(i < n) {
        int j = i;
        while(j < n && s[j] == s[i]) j++; // finding same char length
        if(j - i > 1) {
            int pos = 1;
            for(int k=i; k<j; k++) {
                if(pos % 2 == 0) { // we only have to change even pos char
                    char c = 'a';
                    while(c == s[i] || (j != n && c == s[j])) c++;
                    s[k] = c;
                }
                pos++;
            }
        }
        i = j;
    }

    cout << s;

    return 0;
}