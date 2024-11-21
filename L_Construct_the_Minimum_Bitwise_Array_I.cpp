class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto i: nums) {
            bool found = false;
            for(int j=0; j<=i; j++) {
                if((j | (j + 1)) == i) {
                    found = true;
                    ans.push_back(j);
                    break;
                }
            }

            if(!found) ans.push_back(-1);
        }
        return ans;
    }
};