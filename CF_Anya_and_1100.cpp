#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef priority_queue<int> maxHeap;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
const int mod = 1000000007;

void solve() {
    string s;
    cin >> s;
    int size = s.size();
    int count = 0;
    for(int i=0; i<=(size - 4); i++) {
        string temp = "";
        for(int j=i; j<(i + 4); j++) {
            temp += s[j];
        }
        if(temp == "1100") count++;
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int pos, val;
        cin >> pos >> val;
        if(size < 4) cout << "NO\n";\
        else {
            int index = pos - 1;
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}