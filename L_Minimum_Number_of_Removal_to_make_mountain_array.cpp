class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix (n), suffix (n), temp;
        temp.push_back(nums[0]); prefix[0] = 1;
        for(int i=1; i<n; i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                prefix[i] = temp.size();
            }
            else {
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
                prefix[i] = index + 1;
            }
        }

        temp.clear();
        temp.push_back(nums[n - 1]);
        suffix[n - 1] = 1;
        for(int i=n-2; i>=0; i--) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                suffix[i] = temp.size();
            }
            else {
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
                suffix[i] = index + 1;
            }
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
            if(prefix[i] == 1 || suffix[i] == 1) continue;
            ans = min(ans, n - (prefix[i] + suffix[i] - 1));
        }
        return ans;
    }
};