class Solution {
public:
    // function to check if given speed is possible or not:
    bool checkSpeed(int speed, vector<int>& dist, double hour)
    {
        double time = 0;
        for(int i=0; i<dist.size(); i++)
        {
            // taking ceil time value for all station except last:
            if(i != dist.size()-1)
            {
                time += ceil(dist[i]  * 1.0 / speed);
                if(time > hour) return false;
            }

            // taking exact time value for last station:
            else
            {
                time += dist[i] * 1.0 / speed;
            }
        }

        if(time <= hour) return true;
        else return false;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        // checking for every speed possible:
        int low = 1;
        int high = 1e8;

        // if no speed will come out to be possible -1 will be returned:
        int ans = -1;

        // Binary Search Operation:
        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            bool isPoss = checkSpeed(mid, dist, hour);

            // if mid speed is poss, then check for lower speed:
            if(isPoss)
            {
                high = mid - 1;
                ans = mid;
            }

            // if mid speed is not possible then look for higher speed then mid:
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};