class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ans = "";
        for(int i=0; i<words.size(); i++)
        {
            char x = words[i][0];
            ans.push_back(x);
        }
        
        if(ans == s) return true;
        else return false;
    }
};