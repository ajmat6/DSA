class Solution {
public:
    int solve(vector<int>& nums, int k, int prev, int curr, vector<vector<int>>& dp)
    {
        if(curr == nums.size()) return 0;

        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];

        int ans = 0;
        if(prev == -1 || curr - prev <= k)
        {
            int take = nums[curr] + solve(nums, k, curr, curr + 1, dp);
            int notTake = solve(nums, k, prev, curr + 1, dp);
            return dp[prev+1][curr] = max(take, notTake);
        }

        return dp[prev+1][curr] = ans;
    }

    int solve2(vector<int>& nums, int k)
    {
        vector<vector<int>> dp (nums.size() + 1, vector<int> (nums.size() + 1, 0));

        for(int curr=nums.size()-1; curr>=0; curr--)
        {
            for(int prev=curr-1; prev>=-1; prev--)
            {
                int ans = 0;
                if(prev == -1 || curr - prev <= k)
                {
                    int take = nums[curr] + dp[curr+1][curr];
                    int notTake = dp[curr+1][prev+1];
                    dp[curr][prev+1] = max(take, notTake);
                }
            }
        }

        return dp[0][0];
    }

    int striver(vector<int> nums, int k)
    {
        vector<int> dp (nums.size() + 1, 0);

        for(int i=0; i<nums.size(); i++)
        {
            dp[i] = nums[i];
        }

        int sum = dp[0];
        for(int curr=0; curr<nums.size(); curr++)
        {
            for(int prev=0; prev<curr; prev++)
            {
                if(curr - prev <= k)
                {
                    dp[curr] = max(dp[curr], nums[curr] + dp[prev]);
                }
            }

            sum = max(sum, dp[curr]);
        }

        return sum;
    }

    int tab(vector<int>& nums, int k)
    {
        vector<int> dp (nums.size(), 0);
        for(int i=0; i<nums.size(); i++)
        {
            dp[i] = nums[i];
        }

        int sum = dp[0];
        for(int curr=1; curr<nums.size(); curr++)
        {
            dp[curr] = nums[curr];
            for(int prev=curr-1; curr-prev<=k && prev >= 0; prev--)
            {
                dp[curr] = max(dp[curr], nums[curr] + dp[prev]);
            }

            sum = max(sum, dp[curr]);
        }

        return sum;
    }

    int optimize(vector<int>& nums, int k)
    {
        vector<int> dp (nums.size(), 0);
        dp[0] = nums[0];
        // max heap:
        priority_queue<pair<int, int>> pq;
        pq.push({dp[0], 0});

        int ans = dp[0];
        for(int curr=1; curr<nums.size(); curr++)
        {
            while(!pq.empty() && curr - pq.top().second > k) pq.pop();

            int maxPrevSum = pq.top().first;
            dp[curr] = max(nums[curr], nums[curr] + maxPrevSum);

            // pusing new index sum into pq:
            pq.push({dp[curr], curr});

            ans = max(ans, dp[curr]);
        }

        return ans;
    }

    int usingDeque(vector<int>& nums, int k)
    {
        vector<int> dp (nums.size(), 0);
        dp[0] = nums[0];

        // deque:
        deque<int> dq;
        dq.push_back(0);

        int ans = dp[0];
        for(int curr=1; curr<nums.size(); curr++)
        {
            while(!dq.empty() && curr - dq.front() > k) dq.pop_front();

            int maxPrevSum;
            if(!dq.empty()) maxPrevSum = dp[dq.front()];
            else maxPrevSum = 0;

            dp[curr] = max(nums[curr], nums[curr] + maxPrevSum);

            // now we have to make the deque in decreasing order of its respective values in dp:
            while(!dq.empty() && dp[dq.back()] <= dp[curr]) dq.pop_back();
            dq.push_back(curr);

            ans = max(ans, dp[curr]);
        }

        return ans;
    }

    int constrainedSubsetSum(vector<int>& nums, int k) {
        // vector<vector<int>> dp (nums.size() + 1, vector<int> (nums.size() + 1, -1));
        // int ans = solve(nums, k, -1, 0, dp);

        // int ans = solve2(nums, k);
        // if(ans == 0)  return *max_element(nums.begin(), nums.end());
        // else return ans;

        // int ans = striver(nums, k);
        // if(ans == 0)  return *max_element(nums.begin(), nums.end());
        // else return ans;

        // return tab(nums, k);

        // return optimize(nums, k);

        return usingDeque(nums, k);
    }
};