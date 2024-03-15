class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        long long maxSide = -1;
        for(int i=0; i<bl.size(); i++) {
            for(int j=i+1; j<bl.size(); j++) {
                int sqBlx = max(bl[i][0], bl[j][0]);
                int sqBly = max(bl[i][1], bl[j][1]);
                int sqTrx = min(tr[i][0], tr[j][0]);
                int sqTry = min(tr[i][1], tr[j][1]);

                int x = sqTrx - sqBlx;
                int y = sqTry - sqBly;

                if(x >= 1 && y >= 1) {
                    long long side = min(x, y);
                    maxSide = max(maxSide, side);
                }
            }
        }

        return maxSide == -1 ? 0 : (maxSide * maxSide);
    }
};