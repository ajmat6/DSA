class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // brute force:
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<=(n-k); i++) {
            int start = nums[i];
            bool poss = true;
            for(int j=i+1; j<(i+k); j++) {
                if(nums[j] != start + 1) {
                    poss = false;
                    break;
                }
                start += 1;
            }
            if(poss) ans.push_back(start);
            else ans.push_back(-1);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) return nums;

        int count = 1;
        vector<int> ans;
        int n = nums.size();
        for(int i=1; i<n; i++) {
            if(nums[i] == nums[i - 1] + 1) count += 1;
            else count = 1;
            if(i >= (k - 1)) {
                if(count >= k) ans.push_back(nums[i]);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};