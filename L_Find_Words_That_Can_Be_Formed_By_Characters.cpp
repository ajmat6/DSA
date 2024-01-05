class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(auto i: chars) mp[i]++;

        int ans = 0;
        for(int i=0; i<words.size(); i++)
        {
            unordered_map<char, int> mp2;
            for(auto j: words[i])
            {
                mp2[j]++;
            }

            bool flag = true;
            for(auto j: mp2)
            {
                char ch = j.first;
                if(mp.find(ch) == mp.end() || mp[ch] < j.second)
                {
                    flag = false;
                    break;
                }
            }

            if(flag) ans += words[i].size();
        }
        return ans;
    }
};