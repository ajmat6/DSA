class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // using priority_queue:
        // priority_queue<int> pq;
        // for(auto i: happiness) pq.push(i);
        // long long ans = pq.top(); pq.pop(); k -= 1; int time = 1;
        // while(k) {
        //     int happValue = pq.top(); pq.pop();
        //     happValue -= time;
        //     if(happValue > 0) {
        //         ans += happValue;
        //         time++;
        //         k -= 1;
        //     }
        //     else break;
        // }
        // return ans;

        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = 0; int time = 0;
        for(int i=0; i<happiness.size() && k > 0; i++) {
            if(happiness[i] - time > 0) {
                ans += happiness[i] - time;
                time++;
                k -= 1;
            }
            else break;
        }
        return ans;
    }
};