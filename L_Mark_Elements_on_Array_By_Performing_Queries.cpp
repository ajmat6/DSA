typedef long long ll;

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        ll sum = 0;
        for(auto i: nums) sum += i;
        
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for(int i=0; i<nums.size(); i++) pq.push({nums[i], i});
        
        vector<int> mark (nums.size(), 0);
        
        vector<ll> ans;
        for(auto i: queries) {
            ll index = i[0];
            ll k = i[1];
            
            // mark index:
            if(mark[index] == 0) {
                mark[index] = 1;
                sum -= nums[index];
            }
            
            while(!pq.empty() && k > 0) {
                auto topp = pq.top(); pq.pop();
                if(topp.second != index && mark[topp.second] == 0) {
                    mark[topp.second] = 1;
                    sum -= topp.first;
                    k--;
                }
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};