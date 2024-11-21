class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // s1 += " " + s2;
        // unordered_map<string, int> mp;
        // int index = 0;
        // while(index < s1.size()) {
        //     string temp = "";
        //     while(index < s1.size() && s1[index] != ' ') {
        //         temp += s1[index];
        //         index++;
        //     }
        //     index++;
        //     mp[temp]++;
        // }

        // vector<string> ans;
        // for(auto i: mp) {
        //     if(i.second == 1) ans.push_back(i.first);
        // }
        // return ans;



        stringstream s(s1 + " " + s2);
        unordered_map<string, int> mp;
        string temp = "";
        while(s >> temp) mp[temp]++; // it will break at every space
        vector<string> ans;
        for(auto i: mp) {
            if(i.second == 1) ans.push_back(i.first);
        }
        return ans;
    }
};