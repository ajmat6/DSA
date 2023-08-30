class Solution {
public:
    // easy two pointer track:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;

        while(i < str1.size() && j < str2.size())
        {
            if(str1[i] == str2[j])
            {
                i++;
                j++;
            }

            // if curr index char of str1 is not equal to str2, then change str1 index value, if now equal -> same as above else i++
            else
            {
                // change curr index char:
                int pos = str1[i] - 'a';
                int newPos = (pos + 1) % 26;

                char newChar = 'a' + newPos;
                
                str1[i] = newChar;
                if(str1[i] == str2[j])
                {
                    i++;
                    j++;
                }
                else i++;
            }
        }

        if(j == str2.size()) return true;
        else return false;
    }
};