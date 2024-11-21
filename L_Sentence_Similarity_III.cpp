class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 < n2) return areSentencesSimilar(s2, s1); // need to insert only in s2

        int low1 = 0, low2 = 0;
        int high1 = n1 - 1, high2 = n2 - 1;
        while(low2 < n2 && s1[low1] == s2[low2]) {
            low1++;
            low2++;
        }
        if(low2 == n2 && (low1 == n1 || s1[low1] == ' ')) return true;

        while(high2 >= 0 && s1[high1] == s2[high2]) {
            high1--;
            high2--;
        }
        if(high2 == -1 && (high1 == -1 || s1[high1] == ' ')) return true;

        if(low2 > high2 && s1[low1 - 1] == ' ' && s1[high1 + 1] == ' ') return true;
        return false;
    }
};