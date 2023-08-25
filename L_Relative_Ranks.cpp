class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // copying score array into temp array:
        vector<int> temp = score;
        
        // Sorting temp array into decreasing order:
        sort(temp.begin(), temp.end(), greater<int>());

        // Mapping of values:
        unordered_map<int, string> m;
        for(int i=0; i<temp.size(); i++)
        {
            if(i==0) m[temp[0]] = "Gold Medal";
            else if(i==1) m[temp[1]] = "Silver Medal";
            else if(i==2) m[temp[2]] = "Bronze Medal";

            else m[temp[i]] = to_string(i+1);
        }

        // Creating ans array:
        vector<string> ans;
        for(int i=0; i<score.size(); i++)
        {
            ans.push_back(m[score[i]]);
        }

        return ans;
    }
};