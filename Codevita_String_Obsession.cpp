#include<bits/stdc++.h>
using namespace std;

int dfs(string& s, vector<string>& sub, unordered_map<string, int>& mp, unordered_map<string, int>& dp) {
    if(s.size() == 0) return 0;
    if(dp.count(s)) return dp[s];

    int ans = 0;
    int size = sub.size();
    for(int i=0; i<size; i++) {
        if(mp[sub[i]] == 0) {
            size_t index = s.find(sub[i]);
            if(index != string::npos) {
                string first = s.substr(0, index);
                string second = s.substr(index, sub[i].size());
                string third = s.substr(index + sub[i].size(), s.size() - (index + sub[i].size()));

                s = first + third;
                mp[sub[i]] = 1;
                ans = max(ans, 1 + dfs(s, sub, mp, dp));
                mp[sub[i]] = 0;
                s = first + second + third;
            }
        }
    }
    return dp[s] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> sub;
    unordered_map<string, int> mp;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        sub.push_back(s);
        mp[s] = 0;
    }

    string S;
    cin >> S;

    unordered_map<string, int> dp;
    cout << dfs(S, sub, mp, dp);

    return 0;
}

