class Solution {
public:
    int solve(string& s) {
        if(s.size() == 1) return 0;

        if(s.back() == '0') s.pop_back(); // divide by two in even no (right shift by one, so popping)
        else {
            int index = s.size() - 1;
            while(index >= 0 && s[index] == '1') {
                s[index] = '0';
                index--;
            }
            if(index >= 0) s[index] = '1';
            else s = "1" + s;
        }
        return 1 + solve(s);
    }
    int numSteps(string s) {
        // using recursion:
        // return solve(s);

        // using iterative method:
        int ans = 0;
        while(s.size() > 1) {
            if(s.back() == '0') s.pop_back();
            else {
                int index = s.size() - 1;
                while(index >= 0 && s[index] == '1') {
                    s[index] = '0';
                    index--;
                }
                if(index >= 0) s[index] = '1';
                else s = "1" + s;
            }
            ans++;
        }
        return ans;
    }
};