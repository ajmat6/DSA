class Solution {
public:
    int checkUnique(string& s, int low, int high)
    {
        int count = 0;
        unordered_set<char> st;
        for(int i=low + 1; i<high; i++)
        {
            if(st.find(s[i]) == st.end())
            {
                st.insert(s[i]);
                count++;
            }
        }

        return count;
    }

    int countPalindromicSubsequence(string s) {
        // unordered_map<char, int> first;
        // unordered_map<char, int> last;

        // for(int i=0; i<s.size(); i++)
        // {
        //     if(first.find(s[i]) == first.end()) first[s[i]] = i;
        //     last[s[i]] = i;
        // }

        // // for each diff char check no of unique characters b/w first and last position if diff b/w first and last postion is >= 3:
        // int ans = 0;
        // for(auto i: first)
        // {
        //     int firstIndex = i.second;
        //     int lastIndex = last[i.first];

        //     if(lastIndex - firstIndex >= 2)
        //     {
        //         ans += checkUnique(s, firstIndex, lastIndex);
        //     }
        // }

        // return ans;

        int ans = 0;
        for(int i=0; i<26; i++)
        {
            int firstIndex = s.find('a' + i);
            int lastIndex = s.rfind('a' + i);

            if(firstIndex != -1 && lastIndex != -1 && lastIndex - firstIndex >= 2)
            {
                ans += checkUnique(s, firstIndex, lastIndex);
            }
        }

        return ans;
    }
};