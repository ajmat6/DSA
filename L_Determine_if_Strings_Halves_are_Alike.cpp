class Solution {
public:
    bool check(char i)
    {
        return i == 'A' || i == 'a' || i == 'E' || i == 'e' || i == 'I' || i == 'i' || i ==   'O' || i == 'o' || i == 'U' || i == 'u';
    }

    bool halvesAreAlike(string s) {
        int n = s.size();

        int count1 = 0, count2 = 0;
        for(int i=0; i<n/2; i++)
        {
            if(check(s[i])) count1++;
            if(check(s[n / 2 + i])) count2++;
        }

        return count1 == count2;
    }
};