class Solution {
public:
    int minDeletions(string s) {
        // maps for storing each char count:
        unordered_map<char, int> m1;

        for(auto i: s)
        {
            char c = i;
            m1[c]++;
        }

        // for(auto i: m1)
        // {
        //     m2[i.second].insert(i.first);
        // }

        // // Greedy:
        // int ans = 0;
        // for(int i=0; i<s.size(); i++)
        // {
        //     char c = s[i];
        //     if(m2[m1[c]].size() > 1)
        //     {
        //         ans++;
        //         m1[c]--;

        //         auto it = m2.find(m1[c] + 1); // finding the count key in second map
        //         if(it != m2.end())
        //         {
        //             it -> second.erase(c);
        //             m2[m1[c]].insert(c);
        //         }
        //     }

        //     // if(i == s.size()-1)
        //     // {
        //     //     if(m2[m1[s[i]]].size() > 1) ans++;
        //     // }
        // }

        // return ans;
        unordered_set<int> st;
        int ans = 0;

        // traversing over map:
        for(auto i: m1)
        {
            int freq = i.second;
            while(freq != 0 && st.find(freq) != st.end()) // freq cannot go negative, if it is means char is completely removed
            {
                freq--;
                ans++;
            }

            st.insert(freq);
        }

        return ans;
    }
};