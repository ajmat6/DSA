class Solution {
public:
    bool checkMin(long long min, vector<int>& nums, int n)
    {
        long long count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            // adding each battery min at each iteration:
            count += nums[i];

            // if count is satisfying min it means one computer is satisfied and save the remaining min it could provide:
            if(count >= min)
            {
                count = count - min;
                n--;
            }

            if(n == 0) return true;
        }

        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int i=0; i<batteries.size(); i++)
        {
            sum += batteries[i];
        }

        long long low = 1;
        long long high = sum;
        long long ans = 1;
        sort(batteries.begin(), batteries.end());

        while(low <= high)
        {
            long long mid = low + (high - low) / 2;

            bool isPoss = checkMin(mid, batteries, n);

            if(isPoss)
            {
                low = mid + 1;
                ans = mid;
            }

            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};