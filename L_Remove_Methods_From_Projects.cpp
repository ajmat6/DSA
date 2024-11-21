class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adjList, int num, unordered_map<int, int>& mp, vector<int>& vis) {
        vis[num] = 1;
        for(auto i: adjList[num]) {
            if(vis[i] == 0) {
                mp[i]++;
                dfs(adjList, i, mp, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {
        unordered_map<int, vector<int>> adjList;
        for(auto i: in) {
            adjList[i[0]].push_back(i[1]);
        }

        vector<int> vis (n, 0);
        unordered_map<int, int> mp;  mp[k]++;
        dfs(adjList, k, mp, vis);

        for(auto i: adjList) {
            for(auto j: i.second) {
                if(mp.count(i.first) == 0 && mp.count(j) == 1) {
                    mp.clear();
                    break;
                }
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(mp.count(i) == 0) ans.push_back(i);
        }
        return ans;
    }
};