class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul1 = 1;
        int mul2 = 1;
        int zero = 0;
        for(auto i: nums) {
            if(i != 0) mul1 *= i;
            else zero++;
            mul2 *= i;
        }

        vector<int> ans;
        for(auto i: nums) {
            if(i != 0) ans.push_back(mul2 / i);
            else {
                if(zero == 1) ans.push_back(mul1);
                else ans.push_back(0);
            }
        }

        return ans;
    }
};