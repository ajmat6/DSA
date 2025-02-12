class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();
        // while(s.size() >= m && s.find(part) < n) s.erase(s.find(part), m); // removing part from s
        // return s;

        // string ans;
        // for(auto &i: s) {
        //     ans.push_back(i);
        //     if(ans.size() >= m && ans.substr(ans.size() - m, m) == part) // checking last m chars
        //         ans.erase(ans.size() - m, m);
        // }
        // return ans;


        // using kmp left:
    }
};