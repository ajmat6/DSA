class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        int index = 0;
        string ans = "";
        while(index < n) {
            int count = 0;
            string temp = "";
            while(index < n && count != k) {
                temp += s[index++];
                count++;
            }

            // I have sub string here:
            int totalSum = 0;
            for(auto i: temp) totalSum += (i - 'a');
            int hashedChar = totalSum % 26;
            char ch = 'a' + hashedChar;
            ans += ch;
        }

        return ans;
    }
};