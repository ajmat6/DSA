class Solution {
public:
    // upper bound binary search:
    // int findIndex(vector<pair<int, int>>& nums, int value) {
    //     int low = 0; 
    //     int high = nums.size() - 1;
    //     while(low < high) {
    //         int mid = low + (high - low) / 2;
    //         if(nums[mid].first <= value) low = mid + 1;
    //         else high = mid;
    //     }
    //     return high;
    // }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // vector<pair<int, int>> nums;
        // for(int i=0; i<profit.size(); i++) nums.push_back({difficulty[i],  profit[i]});
        // sort(nums.begin(), nums.end());

        // int maxProfit = INT_MIN;
        // for(int i=0; i<nums.size(); i++) {
        //     maxProfit = max(maxProfit, nums[i].second);
        //     profit[i] = maxProfit;
        // }

        // int ans = 0;
        // for(auto &i: worker) {
        //     int index = upper_bound(nums.begin(), nums.end(), make_pair(i, INT_MAX)) - nums.begin();
        //     if(index != 0) ans += profit[index - 1];
        // }

        // return ans;



        // using two pointers at upper bound place:
        vector<pair<int, int>> nums;
        for(int i=0; i<profit.size(); i++) nums.push_back({difficulty[i],  profit[i]});
        sort(nums.begin(), nums.end());
        sort(worker.begin(), worker.end());

        int ans = 0; int maxProfit = 0; int index = 0;
        for(auto &i: worker) {
            while(index < nums.size() && nums[index].first <= i) {
                maxProfit = max(maxProfit, nums[index].second);
                index++;
            }
            ans += maxProfit;
        }

        return ans;
    }
};