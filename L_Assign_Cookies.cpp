class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // using sort and greedy: nlogn + mlogm + min(n, m) is time and const space:
        // sort(g.begin(), g.end());
        // sort(s.begin(), s.end());

        // int count = 0;
        // int left = 0; int right = 0;
        // while(left < g.size() && right < s.size()) {
        //     if(g[left] <= s[right]) {
        //         count++;
        //         left++;
        //     }
        //     right++;
        // }
        // return count;



        // using heap:
        priority_queue<int, vector<int>, greater<int>> greed;
        priority_queue<int, vector<int>, greater<int>> cook;
        for(auto i: g) greed.push(i);
        for(auto i: s) cook.push(i);

        int ans = 0;
        while(!greed.empty() && !cook.empty()) {
            if(greed.top() <= cook.top()) {
                ans += 1;
                greed.pop();
            }
            cook.pop();
        }
        return ans;
    }
};