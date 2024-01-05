class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int ans = 0;

        for(int i=k; i<=k*26 && i<=word.size(); i+=k)
        {
            int times = i / k;
            int len = i; // current window  max size
            int startIndex = 0;
            unordered_map<char, int> mp;

            for(int j=0; j<word.size(); j++)
            {
                if(j == 0 || abs((word[j] - 'a') - (word[j-1] - 'a')) > 2)
                {
                    mp.clear();
                    startIndex = j;
                }

                mp[word[j]]++;

                if(j - startIndex + 1 >= len) // if window becomes equal to current max window length equal 
                {
                    int timesCount = 0;
                    auto it = mp.begin();
                    for(; it!=mp.end(); it++)
                    {
                        if(it -> second != k) break;
                        else timesCount++;
                    }
                    if(it == mp.end() && timesCount == times) ans++;

                    // decrease current window lower freq:
                    mp[word[j - (len - 1)]]--;
                    if(mp[word[j - (len - 1)]] == 0) mp.erase(word[j - (len - 1)]);
                }
            }
        }

        return ans;
    }
};