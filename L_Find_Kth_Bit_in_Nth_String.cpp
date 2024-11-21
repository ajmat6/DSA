class Solution {
public:
    string alternate(string s) {
        for(auto &i: s) {
            if(i == '0') i = '1';
            else i = '0';
        }
        return s;
    }

    string reverseString(string s) {
        int low = 0;
        int high = s.size() - 1;
        while(low < high) swap(s[low++], s[high--]);
        return s;
    }

    void dfs(string& s, int& n, int& k, char& ans, int no) {
        if(no == n) {
            ans = s[k - 1];
            return;
        }

        s = s + "1" + reverseString(alternate(s));
        dfs(s, n, k, ans, no + 1);
    }

    char findKthBit(int n, int k) {
        // brute force using recursion:
        // char ans = 'a';
        // string s = "0";
        // dfs(s, n, k, ans, 1);
        // return ans;


        // using position determination
        if(n == 1) return '0';
        int len = (1 << n) - 1;
        int mid = len / 2 + 1;
        if(k == mid) return '1';
        else if(k < mid) return findKthBit(n - 1, k);
        return findKthBit(n - 1, len - k + 1) == '0' ? '1' : '0';
    }
};