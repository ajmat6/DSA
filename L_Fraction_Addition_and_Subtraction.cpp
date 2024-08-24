class Solution {
public:
    int findGCD(int a, int b) {
        if(a == 0) return b;
        return findGCD(b % a, a);
    }

    string fractionAddition(string ex) {
        int num = 0;
        int deno = 1;
        int index = 0;
        while(index < ex.size()) {
            bool isNeg = false;
            if(ex[index] == '-') isNeg = true;
            if(ex[index] == '-' || ex[index] == '+') index++;

            int start = index;
            while(index < ex.size() && ex[index] != '/') index++;
            string sub = ex.substr(start, index - start);
            int currNum = stoi(sub);
            if(isNeg) currNum *= -1;

            index++;
            start = index;
            while(index < ex.size()) {
                if(ex[index] == '+' || ex[index] == '-') break;
                index++;
            }

            sub = ex.substr(start, index - start);
            int currDeno = stoi(sub);

            num = (num * currDeno) + (currNum * deno);
            deno = deno * currDeno;
        }

        // find gcd of num and deno:
        int gcd = findGCD(abs(num), abs(deno));
        num /= gcd;
        deno /= gcd;
        string ans = "";
        ans += to_string(num);
        ans += '/';
        ans += to_string(deno);
        return ans;
    }
};