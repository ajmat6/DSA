class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i=0; i<word.size(); i++) {
            if(word[i] == ch) {
                string first = word.substr(0, i + 1);
                reverse(first.begin(), first.end());
                string second  = word.substr(i + 1, word.size() - (i + 1));
                return first + second;
            }
        }
        return word;
    }
};