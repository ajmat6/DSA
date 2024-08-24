class Solution {
public:
    bool isPalindrome(string& s) {
        int low = 0;
        int high = s.size() - 1;
        while(low < high) {
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }

    void solve(string& s, int index, vector<vector<string>>& ans, vector<string>& temp) {
        if(index == s.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i=index; i<s.size(); i++) {
            string sub = s.substr(index, i - index + 1);
            if(isPalindrome(sub)) {
                temp.push_back(sub);
                solve(s, i + 1, ans, temp);
                temp.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, ans, temp);
        return ans;
    }
};