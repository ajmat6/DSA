class Solution {
public:
    void dfs(int n, vector<int>& ans, int curr) {
        if(curr > n) return;
        for(int i=0; i<10; i++) {
            if(curr == 0 && i == 0) continue;
            int res = curr * 10 + i;
            if(res <= n) {
                ans.push_back(res);
                dfs(n, ans, res);
            }
            else return;
        }
    }

    vector<int> lexicalOrder(int n) {
        // using sort: nlogn time and const space:
        // vector<int> ans;
        // for(int i=1; i<=n; i++) ans.push_back(i);
        // sort(ans.begin(), ans.end(), [](int& a, int& b) {
        //     return to_string(a) < to_string(b);
        // });
        // return ans;



        // recursive: n time and n space (recursive space)
        // vector<int> ans;
        // dfs(n, ans, 0);
        // return ans;



        // using trie: do it when learning trie:



        // using iterative:
        vector<int> ans;
        int curr = 1;
        for(int i=1; i<=n; i++) {
            ans.push_back(curr);
            if(curr * 10 <= n) curr *= 10;
            else {
                while(curr % 10 == 9 || curr >= n) curr /= 10;
                curr += 1;
            }
        }
        return ans;
    }
};