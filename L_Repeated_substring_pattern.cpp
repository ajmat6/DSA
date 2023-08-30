class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // string temp = s + s;

        // // removing first and last character from the doubled temp string and then find orinial in it:
        // string sub = temp.substr(1, temp.size() - 2);
        
        // if(sub.find(s) != -1) return true;
        // else return false;

        // 2nd approach:
        int n = s.size();
        for(int i=n/2; i>=1; i--)
        {
            // we will find substring from 0 to ith length and will check that concatinating that substring any no of times (thats why n  % 2 should be zero otherwise it will not divide and we cannot make s) gives s or not:
            if(n % i == 0)
            {
                string sub = s.substr(0, i);
                string check = "";
                int times = n / i;

                for(int j=0; j<times; j++) check += sub;
                if(check == s) return true;
            }
        }

        return false;
    }
};