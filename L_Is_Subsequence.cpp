// TC = O(n) && SC = O(1):
class Solution {
public:
    bool solve(string&s, string& t, int sIndex, int tIndex)
    {
        if(sIndex == s.size()) return true;
        if(tIndex == t.size() && sIndex != s.size()) return false;

        // if current s index element is found in t:
        bool isSub;
        if(t[tIndex] == s[sIndex])
        {
            isSub = solve(s, t, sIndex + 1, tIndex + 1);
        }

        else
        {
            isSub = solve(s, t, sIndex, tIndex + 1);
        }

        return isSub;
    }

    bool isSubsequence(string s, string t) {
        // Using Two Pointers:
        // int i = 0;

        // for(int j=0; j<t.size(); j++)
        // {
        //     if(i <s.size() && t[j] == s[i])
        //     {
        //         i++;
        //     }
        // }

        // if(i == s.size()) return true;
        // else return false;

        // Using Recursion:
        return solve(s, t, 0, 0);
    }
};