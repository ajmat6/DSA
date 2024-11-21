class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto i: nums) {
            int element = i;
            int sum = 0;
            while(element != 0) {
                sum += element % 10;
                element /= 10;
            } 
            ans = min(ans, sum);
        }
        return ans;
    }
};