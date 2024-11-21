class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        if(word1.size() < word2.size()) return 0;

        vector<int> f1 (26);
        for(auto i: word2) f1[i - 'a']++;

        int low = 0;
        int high = 0;
        long long ans = 0;
        int count = word2.size();
        vector<int> f2 (26);

        while(high < word1.size()) {
            int ch = word1[high] - 'a';

            // if curr char is there in word2
            if(f1[ch] > 0) {
                if(f2[ch] < f1[ch]) {
                    count -= 1;
                }
            }

            f2[ch]++;
            while(count == 0) {
                ans += word1.size() - high;
                int toRem = word1[low] - 'a';
                if(f1[toRem] != 0) {
                    if(f2[toRem] == f1[toRem]) count += 1;
                }
                f2[toRem]--;
                low++;
            }
            high++;
        }

        return ans;
    }
};