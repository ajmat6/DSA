class Solution {
public:
    int maxDiff(string& s, char a, char b)
    {
        int Diff = 0;
        int counta = 0;
        int countb = 0;

        for(char ch: s)
        {
            if(ch == a) counta++;
            else if(ch == b) countb++;
            else continue;

            if(countb > 0)
            {
                Diff = max(Diff, counta-countb);
            }

            else if(countb == 0)
            {
                Diff = max(Diff, counta-1); // at least one less than totol substring
            }

            // we are assuming a to be greater in frequency here so set counts to zero if a is less than b:
            if(counta < countb)
            {
                counta = 0;
                countb = 0;
            }
        }

        return Diff;
    }

    int largestVariance(string s) {
        // vector to store count of each character in s:
        unordered_map<char, int> chars;
        int ans = 0;

        for(char c : s)
        {
            if(chars.count(c) == 0) chars[c] = 1;
            else chars[c]++; 
        }

        // checking max variance for each pair of characters:
        for(char a='a'; a<='z'; a++)
        {
            if(chars[a] == 0) continue;
            for(char b='a'; b<='z'; b++)
            {
                if(chars[b] == 0) continue;
                // considering pairs which are present in the string and they both should not be same:
                if(chars[a] > 0 && chars[b] > 0 && a != b)
                {
                    ans = max(ans, maxDiff(s, a, b));
                }
            }
        }

        return ans;
    }
};