class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();

        vector<int> mul (n + m, 0);

        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                mul[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
                mul[i+j] += mul[i+j+1] / 10;
                mul[i+j+1] %= 10;
            }
        }

        string ans = "";
        int i = 0;
        while(i < mul.size() && mul[i] == 0 ) i++;
        while(i < mul.size())
        {
            ans += to_string(mul[i]);
            i++;
        }

        return ans.size() == 0 ? "0" : ans;
    }
};