class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for(auto &i: s) {
            if(i >= '0' && i <= '9') ans.pop_back();
            else ans.push_back(i);
        }
        return ans;
    }
};