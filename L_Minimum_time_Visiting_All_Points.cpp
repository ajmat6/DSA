class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        // int ans = 0;
        // for(int i=1; i<points.size(); i++)
        // {
        //     int x1 = points[i][0]; int y1 = points[i][1];
        //     int x2 = points[i-1][0]; int y2 = points[i-1][1];

        //     int xdist, ydist;
        //     int maxDiagonal = abs(y2 - y1); // I have to find max diagonal dist (ie max y distnace) you have to travel
        //     int xdiagonal = abs(x2 - x1); // x distance you have to travel

        //     // if x distance to be travelled is less than y distance: move diagonal upto x distance and then move vertical upwards in y remaining distance
        //     if(xdiagonal <= maxDiagonal)
        //     {
        //         xdist = xdiagonal;
        //         ydist = maxDiagonal - xdiagonal; // y remaining distance after moving xdist diagonally
        //     } 

        //     // if y distance > x distance
        //     else
        //     {
        //         ydist = maxDiagonal; // first move max y distance diagonally
        //         xdist = xdiagonal - maxDiagonal; // and then move remaining x distance horizontally
        //     } 

        //     ans += xdist + ydist;
        // }

        // return ans;



        // using chebshev distance: when you can move diagonally min distance b/w two points is max(|x2 - x1|, |y2 - y1|)
        int ans = 0;
        for(int i=1; i<points.size(); i++)
        {
            int x1 = points[i][0]; int y1 = points[i][1];
            int x2 = points[i-1][0]; int y2 = points[i-1][1];

            ans += max(abs(x2 - x1), abs(y2 - y1));
        }

        return ans;
    }
};