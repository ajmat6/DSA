class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        vector<int> integers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for(int i=0; i<integers.size(); i++)
        {
            while(num >= integers[i])
            {
                ans +=  roman[i];
                num -= integers[i];
            }
        }

        return ans;
    }
};