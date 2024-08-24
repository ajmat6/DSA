class Solution {
public:
    int appendCharacters(string s, string t) {
        int index1 = 0, index2 = 0;
        while(index1 < s.size() && index2 < t.size()) {
            if(s[index1] == t[index2]) {
                index1++;
                index2++;
            }
            else index1++;
        }

        return t.size() - index2;
    }
};