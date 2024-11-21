class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // using priority_queue: time is nlogn time and space is at worst n
        // priority_queue<pair<int, int>> pq;
        // for(int i=0; i<k; i++) pq.push({nums[i], i});

        // int low = 0;
        // int high = k - 1;
        // vector<int> ans;
        // while(high < nums.size()) {
        //     ans.push_back(pq.top().first);
        //     while(!pq.empty() && pq.top().second <= low) pq.pop();
        //     low++;
        //     high++;
        //     if(high < nums.size()) pq.push({nums[high], high});
        // }
        // return ans;



        // using deque:
        deque<int> q;
        vector<int> ans;
        for(int i=0; i<k; i++) {
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
        }

        int low = 0;
        int high = k - 1;
        while(high < nums.size()) {
            ans.push_back(nums[q.front()]);
            if(q.front() == low) q.pop_front();
            low++; high++;
            while(!q.empty() && high < nums.size() && nums[q.back()] <= nums[high]) q.pop_back();
            if(high < nums.size()) q.push_back(high);
        }
        return ans;
    }
};