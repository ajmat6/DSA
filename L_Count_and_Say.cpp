class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        
        string ans = "1";
        int count = 1;

        while(count < n)
        {
            int prev;
            int countChar = 0;
            string temp = "";
            for(int i=0; i<ans.size(); i++)
            {
                if(i == 0)
                {
                    countChar ++;
                    prev = ans[i] - '0';
                    if(i != ans.size()-1)continue;
                }

                // when next element is different element:
                if(i == ans.size()-1 || ans[i] - '0' != prev)
                {
                    if(i == ans.size()-1 && i != 0 && ans[i] - '0' == prev)
                    {
                        countChar++;
                        // string noOfChar = to_string(countChar);
                        // string whichChar = to_string(prev);
                        // temp += noOfChar + whichChar;

                        // countChar = 0;
                    } 
                    
                    else if(i == ans.size()-1 && i != 0 && ans[i] - '0' != prev)
                    {
                        string noOfChar = to_string(countChar);
                        string whichChar = to_string(prev);
                        temp += noOfChar + whichChar;

                        // string newString = "";
                        // newString.push_back(ans[i]);
                        // temp += "1" + newString;

                        prev = ans[i] - '0';
                        countChar = 1;

                        // countChar = 0;
                    }

                    // else
                    // {
                        string noOfChar = to_string(countChar);
                        string whichChar = to_string(prev);
                        temp += noOfChar + whichChar;

                        countChar = 0;
                    // }
                }

                countChar++;
                prev = ans[i] - '0';
            }

            count++;
            ans = temp;
        }

        return ans;
    }
};