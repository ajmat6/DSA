class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        while(index < s.size()) {
            int count = 0;
            char ch = s[index];
            while(index < s.size() && s[index] == ch) {
                index++;
                count++;
            }
            ans.push_back(ch);
            if(count > 1) ans.push_back(ch);
        }
        return ans; 
    }
};