class Solution {
public:
    string compressedString(string word) {
        string res = "";
        int index = 0;
        int n = word.size();
        while(index < n) {
            int count = 1;
            char c = word[index++];
            while(index < n && word[index] == c && count < 9) {
                count++;
                index++;
            }
            res.push_back(count + '0');
            res.push_back(c);
        }
        return res;
    }
};