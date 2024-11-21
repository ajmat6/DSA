class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto &i: nums) {
            if(i == 2) {
                ans.push_back(-1);
                continue;
            }

            // find first unset bit and subtract first unset bit pos - 1 pos value from curr no
            int count = 0;
            int num = i;
            while(num & 1) {
                count += 1;
                num /= 2;
            }

            ans.push_back(i - (1 << (count - 1)));
        }
        return ans;
    }
};