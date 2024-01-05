class Solution {
public:
    string sortVowels(string s) {
        string ans = "";
        vector<char> v;

        for(auto i: s)
        {
            if(i == 'a' || i == 'A' || i == 'e' || i == 'E' || i == 'i' || i == 'I' || i == 'o' || i == 'O' || i == 'u' || i == 'U')
            {
                v.push_back(i);
            }
        }

        sort(v.begin(), v.end());

        int j = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
            {
                ans.push_back(v[j]);
                j++;
            }

            else ans.push_back(s[i]);
        }

        return ans;
    }
};