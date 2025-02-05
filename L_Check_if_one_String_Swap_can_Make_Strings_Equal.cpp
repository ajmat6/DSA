class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int prevIndex = -1;
        int notMatchCount = 0;
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) {
                notMatchCount++;
                if(notMatchCount == 2) swap(s1[i], s1[prevIndex]);
                else if(notMatchCount == 1) prevIndex = i;
                else return false;
            }
        }

        return s1 == s2;
    }
};