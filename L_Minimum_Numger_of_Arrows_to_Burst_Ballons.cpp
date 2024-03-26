class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0;
        int prevEnd = points[0][1];

        

        for(int i=1; i<points.size(); i++) {
            if(points[i][0] > prevEnd) {
                ans++;
                prevEnd = points[i][1];
            }

            else if(points[i][1] < prevEnd) prevEnd = points[i][1];
        }

        return ans + 1;
    }
};