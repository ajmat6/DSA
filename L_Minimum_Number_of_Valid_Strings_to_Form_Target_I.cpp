class Node {
    Node* links[26] = {nullptr};
    bool flag = false;
    public:
    bool containsKey(char ch) {
        if(links[ch - 'a'] != nullptr) return true;
        return false;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};


class Solution {
public:
    Node* root;
    Solution() {
        root = new Node();
    }

    void insert(string word) {
        Node* temp = root;
        for(int i=0; i<word.size(); i++) {
            cout << word[i] << endl;
            if(!temp -> containsKey(word[i])) temp -> put(word[i], new Node());
            temp = temp -> get(word[i]);
        }
    }

    int solve(vector<string>& words, string& target, int index, vector<int>& dp) {
        if(index == target.size()) return 0;
        if(dp[index] != -1) return dp[index];

        string temp = "";
        int ans = INT_MAX;
        Node* node = root;
        for(int i=index; i<target.size(); i++) {
            if(node -> containsKey(target[i])) {
                int call = solve(words, target, i + 1, dp);
                if(call != INT_MAX) ans = min(ans, 1 + call);
                node = node -> get(target[i]);
            }
            else break;
        }
        return dp[index] = ans;
    }

    int tab(vector<string>& words, string& target) {
        vector<int> dp (target.size() + 2, 0);
        for(int index=target.size()-1; index>=0; index--) {
            string temp = "";
            int ans = INT_MAX;
            Node* node = root;
            for(int i=index; i<target.size(); i++) {
                if(node -> containsKey(target[i])) {
                    int call = dp[i + 1];
                    if(call != INT_MAX) ans = min(ans, 1 + call);
                    node = node -> get(target[i]);
                }
                else break;
            }
            dp[index] = ans;
        }
        return dp[0];
    }

    int minValidStrings(vector<string>& words, string& target) {
        for(auto i: words) insert(i);

        // memorisation gives tle:
        // vector<int> dp (target.size(), -1);
        // int ans = solve(words, target, 0, dp);
        // return ans == INT_MAX ? -1 : ans;

        int ans = tab(words, target);
        return ans == INT_MAX ? -1 : ans;
    }
};