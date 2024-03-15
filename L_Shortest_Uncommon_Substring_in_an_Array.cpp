class Solution {
public:
    static bool cmp(string &a, string& b) {
        if(a.size() < b.size()) return true;
        else if(a.size() > b.size()) return false;
        else return a <= b;
    }
    
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        map<string, int> mp;
        vector<vector<string>> sub (n, vector<string> ());
        for(int i=0; i<n; i++) {
            int m = arr[i].size();
            for(int j=0; j<m; j++) {
                string temp = "";
                for(int k=j; k<m; k++) {
                    temp += arr[i][k];
                    if(find(sub[i].begin(), sub[i].end(), temp) != sub[i].end()) continue;
                    mp[temp]++;
                    sub[i].push_back(temp);
                }
            }

            sort(sub[i].begin(), sub[i].end(), cmp);
        }
        
        vector<string> ans (n, "");
        for(int i=0; i<n; i++) {
            for(auto j: sub[i]) {
                if(mp[j] == 1) {
                    ans[i] = j;
                    break;
                }
            }
        }

        return ans;
    }
};