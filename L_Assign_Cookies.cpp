class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int greed = 0;
        int cook = 0;

        while(greed < g.size() && cook < s.size())
        {
            if(s[cook] >= g[greed]) greed++;
            cook++;
        }

        return greed;
    }
};