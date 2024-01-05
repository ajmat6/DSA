class Solution {
public:
    bool checkSubstring(string& s, unordered_map<string, int> mp, int oneWordSiz)
    {
        for(int i=0; i<s.size(); i+=oneWordSize)
        {
            string sub = s.substr(i, oneWordSize);

            if(mp.find(sub) != mp.end())
            {
                if(mp[sub] > 0) mp[sub]--;
                else return false;
            }
            else return false;
        }

        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int sSize = s.size();
        int oneWordSize = words[0].size();
        int wordSize = words.size();
        int totalWordsWords = oneWordSize * wordSize;

        // if s size is less than total words combine of words words:
        if(sSize < totalWordsWords) return {};

        unordered_map<string, int> mp;
        vector<int> ans;

        // mapping of words strings:
        for(auto i: words)
        {
            mp[i]++;
        }

        for(int i=0; i<=(sSize - totalWordsWords); i++)
        {
            string sub = s.substr(i, totalWordsWords);
            if(checkSubstring(sub, mp, oneWordSize))
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};