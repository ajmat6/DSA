class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(auto i: nums) pq.push(i);
        
        int count = 0;
        while(pq.top() < k) {
            ll first = pq.top(); pq.pop();
            ll second = pq.top(); pq.pop(); 
            ll res = 2 * min(first, second) + max(first, second);
            pq.push(res);
            count++;
        }
        return count;
    }
};