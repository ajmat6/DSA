class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto i: details) ((i[11] - '0') * 10 + (i[12] - '0')) > 60 ?  ans += 1 : ans += 0;
        return ans;
    }
};