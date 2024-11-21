class Solution {
public:
    char kthCharacter(int k) {
        string temp = "a";
        while(temp.size() < k) {
            string s = temp;
            for(int i=0; i<s.size(); i++) {
                if(s[i] == 'z') s[i] = 'a';
                else s[i] += 1;
            }
            temp += s;
        }
        return temp[k - 1];
    }
};