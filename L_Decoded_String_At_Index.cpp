class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long totalLength = 0;

        for(auto i: s)
        {
            if(i >= 'a' && i <= 'z')
            {
                totalLength += 1;
            }

            else
            {
                totalLength *= i - '0';
            }
        }

        // now reverse traverse and do modulus for circularly finding the kth value:
        for(int i=s.size()-1; i>=0; i--)
        {
            if(isdigit(s[i]))
            {
                totalLength = totalLength / (s[i] - '0');
                k = k % totalLength;
            }

            else
            {
                if(totalLength == k || k == 0) // k is zero for eg aa and k = 1 -> test case 3
                {
                    return string("") + s[i];
                }

                else
                {
                    totalLength--;
                }
            }
        }

        return "";
    }
};