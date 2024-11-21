// TC is O(8n) and SC is O(7n)

class Solution {
public:
    // manacher algorithm:
    vector<int> p;
    void build(string& s) {
        // create hash string:
        string t;
        for(auto i: s) {
            t += string("#") + i;
        }
        t += "#";

        // p array creation:
        int n = t.size();
        p.resize(n, 1);
        int l = 1, r = 1;
        for(int i=1; i<n; i++) {
            if(l + r - i >= 0) p[i] = max(1, min(r - i, p[l + r - i]));
            while(i - p[i] >= 0 && i + p[i] < n && t[i - p[i]] == t[i + p[i]]) p[i]++;
            if(i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    bool isPalindrome(int& low, int& high) {
        int center = (low + high) / 2;
        bool odd = (high % 2 == low % 2);
        int corrCenter = (2 * center) + 1 + (!odd);
        int centerLen = p[corrCenter] - 1;
        if((high - low + 1) <= centerLen) return true; 
        return false;
    }

    void dfs(vector<vector<int>>& adjList, string& s, int node, vector<int>& tin, vector<int>& tout, string& temp) {
        tin[node] = temp.size();
        for(auto &i: adjList[node]) dfs(adjList, s, i, tin, tout, temp);
        tout[node] = temp.size();
        temp += s[node];
    }

    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> adjList (n);
        for(int i=1; i<n; i++) {
            adjList[parent[i]].push_back(i);
        }

        string temp = "";
        vector<int> tin (n), tout (n);
        dfs(adjList, s, 0, tin, tout, temp);

        build(temp); 
        vector<bool> ans (n, false);
        for(int i=0; i<n; i++) {
            if(isPalindrome(tin[i], tout[i])) ans[i] = true;
        }
        return ans;
    }
};