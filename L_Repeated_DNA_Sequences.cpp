class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};

        int size = s.size();
        int low = 0;
        int high = 9;

        unordered_set<string> st;
        unordered_set<string> vis;
        vector<string> ans;
        while(high < size)
        {
            // finding substring:
            string str = s.substr(low, high - low + 1);

            // check if str already exist in set:
            if(st.find(str) == st.end())
            {
                st.insert(str);
            }

            else 
            {
                if(vis.find(str) == vis.end())
                {
                    vis.insert(str);
                }
            }

            low++;
            high++;
        }

        ans = {vis.begin(), vis.end()};
        return ans;
    }
};