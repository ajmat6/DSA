class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());

        int ans = INT_MAX;
        int hr = stoi(timePoints[0].substr(0, 2));
        int minn = stoi(timePoints[0].substr(3, 2));
        int prev = hr * 60 + minn;
        for(int i=1; i<n; i++) {
            int hours = stoi(timePoints[i].substr(0, 2));
            int minutes = stoi(timePoints[i].substr(3, 2));
            int curr = hours * 60 + minutes;
            ans = min(ans, curr - prev);
            prev = curr;
        }
        int curr = (hr + 24) * 60 + minn;
        return min(ans, curr - prev);
    }
};