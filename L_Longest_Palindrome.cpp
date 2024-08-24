class Solution {
public:
    int longestPalindrome(string s) {
        // map<char, int> mp;
        // for(auto i: s) mp[i]++;
        // int ans = 0; int greatest = 0;
        // for(auto i: mp) {
        //     if(i.second % 2 == 0) ans += i.second;
        //     else {
        //         greatest = max(greatest, i.second);
        //         ans += i.second - 1;
        //     }
            
        // }
        // return greatest ? ans + 1 : ans;


        // using set:
        unordered_set<char> st;
        int ans = 0;

        for(auto i: s) {
            if(st.find(i) != st.end()) {
                ans += 2;
                st.erase(i);
            }
            else st.insert(i);
        }

        if(st.size() != 0) ans += 1;
        return ans;
    }
};