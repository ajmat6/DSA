class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i = 0;
        for(; i<heights.size()-1; i++) {
            int gap = heights[i + 1] - heights[i];
            if(gap > 0) {
                // using brick first but also pushing in pq for further used by ladder:
                bricks -= gap;
                pq.push(gap);

                if(bricks < 0) {
                    // using ladder for max gap and adding it back to bricks
                    if(ladders != 0) {
                        bricks += pq.top();
                        pq.pop();
                        ladders--;                        
                    }
                    else break;
                }
            }
        }

        return i;
    }
};