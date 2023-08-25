class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        
        for(long long i=0; i<n; i++)
        {
            q.push(arr[i]);
        }
        
        long long ans = 0;
        while(q.size() != 1)
        {
            long long top1 = q.top();
            q.pop();
            long long top2 = q.top();
            q.pop();
            
            long long sumLength = top1 + top2;
            
            ans += sumLength;
            
            q.push(sumLength);
        }
        
        return ans;
    }
};