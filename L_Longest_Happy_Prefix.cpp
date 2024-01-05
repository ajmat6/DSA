class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps (s.size(), 0);
        int i = 1;
        int len = 0;

        while(i < s.size())
        {
            if(s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }

            else
            {
                if(len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else len = lps[len - 1];
            }
        }

        int size = lps[s.size()-1];
        return s.substr(0, size);
    }
};