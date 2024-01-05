class Solution {
public:
    char findTheDifference(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // int i = 0;
        // int j = 0;

        // while(i < s.size())
        // {
        //     if(s[i] != t[j]) return t[j];

        //     i++;
        //     j++;
        // }

        // return t[j];

        // unordered_map<char, int> mp;

        // for(auto i: s) mp[i]++;
        // for(auto i: t)
        // {
        //     if(mp[i] == 0) return i;
        //     else mp[i]--;
        // }

        // return 'a';

        // using xor:
        // char c = '\0';
        // for(auto i: s) c = c ^ i;
        // for(auto i: t) c = c ^ i;

        // return c;

        // using sum:
        int sum = 0;
        for(auto i: t) sum += i;
        for(auto i: s) sum -= i;

        return char(sum);
    }
};