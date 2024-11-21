class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        vector<int> integers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int index = 0;
        while(index < integers.size()) {
            if(num >= integers[index]) {
                ans += roman[index];
                num -= integers[index];
            }
            else index++;
        }
        return ans;
    }
};