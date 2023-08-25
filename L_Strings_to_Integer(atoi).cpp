class Solution {
public:
    int myAtoi(string s) {
        bool isNegative = false;
        int i = 0;

        // step 1: Remove white spaces:
        bool isSpace = true;
        while(isSpace)
        {
            if(s[i] == ' ') i++;
            else isSpace = false;
        }

        string ans = "";

        // check for negative and positive sign:
        if(s[i] == '-' && i != s.size()-1)
        {
            isNegative = true;
            i++;
        }
        else if(s[i] == '+') i++;

        // finding ans string:        
        while(s[i] >= '0' && s[i] <= '9' && i < s.size())
        {
            cout << s[i] << " ";
            ans += s[i];
            i++;
        }

        // if ans string is empty then no integer value is found:
        if(ans.size() == 0) return 0;

        // calculating integer value from ans string:
        long long finalAns = 0;
        bool bada = false;
        for(int i=0; i<ans.size(); i++)
        {
            if(finalAns < INT_MAX)
            {
                cout << finalAns << " ";
                finalAns = finalAns * 10 + ans[i] - '0';
                
                if(finalAns > INT_MAX) bada = true; // for last iteration edge case
            }
            else if(finalAns > INT_MAX)
            {
                bada = true;
                break;
            }
        }

        // checking for out of bound of INT_MAX:
        if(bada && isNegative) return INT_MIN; // if negative
        else if(bada) return INT_MAX;

        if(isNegative) return -1 * finalAns;
        return finalAns;
    }
};