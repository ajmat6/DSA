class Solution {
public:
    int dfs(string& s, int index, unordered_set<string>& st) {
        if(index == s.size()) return 0;

        int ans = INT_MIN;
        string temp = "";
        for(int i=index; i<s.size(); i++) {
            temp.push_back(s[i]);
            if(st.find(temp) == st.end()) {
                st.insert(temp);
                ans = max(ans, 1 + dfs(s, i + 1, st));
                st.erase(temp);
            }
        }
        return ans;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return dfs(s, 0, st);
    }
};





// optimised by adding pruning:
class Solution {
public:
    void dfs(string& s, int index, int count, int& maxCount, unordered_set<string>& st){
        if (count + (s.size() - index) <= maxCount) return; // if current and remaining single characters count can't exceed maxCount till now: Pruning

        if (index == s.size()) {
            maxCount = max(maxCount, count);
            return;
        }

        string temp = "";
        for(int i=index; i<s.size(); i++){
            temp.push_back(s[i]);
            if(st.count(temp) == 0) {
                st.insert(temp);
                dfs(s, i + 1, count + 1, maxCount, st);
                st.erase(temp);
            }
        }
    }

    int maxUniqueSplit(string& s) {
        int maxCount = 0;
        unordered_set<string> st;
        dfs(s, 0, 0, maxCount, st);
        return maxCount;  
    }
};