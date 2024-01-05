class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // finding start and end time of all flowers and counting how many flowers have already bloomed till I came - how many flowers are not blooming:
        vector<int> start;
        vector<int> exit;

        for(auto i: flowers)
        {
            start.push_back(i[0]);
            exit.push_back(i[1]);
        }

        sort(start.begin(), start.end());
        sort(exit.begin(), exit.end());

        vector<int> ans;

        for(auto i: people)
        {
            // finding how many flowers had already bloomed till person came:
            int total = upper_bound(start.begin(), start.end(), i) - start.begin();

            // finding how many flowers vaapas murja gaye:
            int minus = lower_bound(exit.begin(), exit.end(), i) - exit.begin();

            ans.push_back(total - minus);
        }

        return ans;
    }
};