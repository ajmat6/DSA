class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> color, balls;
        for(int i=0; i<queries.size(); i++) {
            int currBall = queries[i][0];
            int currColor = queries[i][1];
            if(balls.count(currBall)) {
                int prevColor = balls[currBall];
                if(--color[prevColor] == 0) color.erase(prevColor);
            }
            color[currColor]++;
            balls[currBall] = currColor;
            ans.push_back(color.size());
        }
        return ans;
    }
};