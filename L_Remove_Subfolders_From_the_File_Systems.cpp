class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        unordered_map<string, int> mp;

        int n = folder.size();
        for(int i=0; i<n; i++) {
            int m = folder[i].size();
            string temp = "";
            bool poss = true;
            int j = 0;
            while(j < m) {
                temp += folder[i][j];
                j += 1;
                while(j < m && folder[i][j] != '/') {
                    temp += folder[i][j];
                    j++;
                }

                if(mp.count(temp)) {
                    poss = false;
                    break;
                }
            }

            if(poss) {
                mp[temp]++;
            }
        }

        vector<string> ans;
        for(auto i: mp) ans.push_back(i.first);
        return ans;
    }
};