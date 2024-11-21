// taking stringstream and stack help:
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp;

        stack<string> st;
        while(ss >> temp) st.push(temp);
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top() + " ";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};



// without space and modifying input string only:
class Solution {
public:
    void reverseString(string& s, int low, int high) {
        while(low < high) swap(s[low++], s[high--]);
    }

    string reverseWords(string s) {
        int low = 0;
        int high = 0;
        int n = s.size();
        while(high < n) {
            while(high < n && s[high] == ' ') high++;
            if(high == n) break;

            int temp = low;
            while(high < n && s[high] != ' ') s[low++] = s[high++];
            reverseString(s, temp, low - 1);
            s[low] = ' ';
            low++;
        }
        s.resize(low - 1); // there is a space in end
        reverseString(s, 0, low - 2);
        return s;
    }
};