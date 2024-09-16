class Solution {
public:
    string convert(string s) {
        int num = stoi(s);
        string ans = "";
        while(num != 1) {
            int rem = num % 2;
            num = num / 2;
            ans += rem + '0';
        }
        ans += num + '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string convertDateToBinary(string date) {
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);
        return convert(year) + "-" + convert(month) + "-" + convert(day);
    }
};