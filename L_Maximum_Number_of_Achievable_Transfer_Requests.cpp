class Solution {
public:
    void solve(vector<vector<int>>& requests, int index, vector<int>& v, int requestCount, int& ans)
    {
        if(index == requests.size())
        {
            // check for the requests for each of the buildings:
            for(auto a: v)
            {
                if(a != 0) return;
            }

            // Storing ans:
            ans = max(ans, requestCount);
            return;
        }

        // Denying the current request:
        solve(requests, index+1, v, requestCount, ans);

        // Accepting the current request: increase and decrease no of requests for each of the buildings:
        v[requests[index][0]]--;
        v[requests[index][1]]++;
        solve(requests, index+1, v, requestCount+1, ans);

        // Backtracking the requests to check for all the possible commibinations of requests:
        v[requests[index][0]]++;
        v[requests[index][1]]--;

    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        vector<int> v (n, 0); // no of requests for each building
        solve(requests, 0, v, 0, ans);
        return ans;
    }
};