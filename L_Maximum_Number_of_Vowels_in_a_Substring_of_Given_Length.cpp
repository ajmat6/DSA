class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        else return false;
    }

    int maxVowels(string s, int k) {
        // Two Pointers:
        int low = 0;
        int high = low + k;

        int ans = 0;
        int count = 0;

        // counting all vowels in first substring of length k:
        for(int i=0; i<high; i++)
        {
            if(isVowel(s[i]))
            {
                count++;
            }
        }

        ans = count;

        low++;
        while(high != s.size())
        {
            if(isVowel(s[low - 1])) count--;
            if(isVowel(s[high])) count++;
            ans = max(ans, count);

            low++;
            high++;
        }

        return ans;
    }
};