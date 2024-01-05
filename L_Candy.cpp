class Solution {
public:
    int candy(vector<int>& ratings) {
        // Prefix sum solution:
        // vector<int> candies (ratings.size(), 1);

        // // checking if curr child has greater rating than prev:
        // for(int i=1; i<ratings.size(); i++)
        // {
        //     if(ratings[i] > ratings[i-1])
        //     {
        //         candies[i] = candies[i-1] + 1;
        //     }
        // }

        // // checking if curr child has lesser rating than prev: updating from last
        // for(int i=ratings.size()-1; i>=1; i--)
        // {
        //     if(ratings[i] < ratings[i-1])
        //     {
        //         candies[i-1] = max(candies[i-1], candies[i] + 1);
        //     }
        // }

        // // sum all candies:
        // int ans = 0;
        // for(auto i: candies) ans += i;
        // return ans;


        // One pass:
        int upCount = 0;
        int downCount = 0;
        int peakCount = 0;
        int total = 1;

        for(int i=1; i<ratings.size(); i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                upCount += 1;
                downCount = 0;
                peakCount = upCount + 1;
                total += peakCount;
            }

            else if(ratings[i] == ratings[i-1])
            {
                upCount = 0;
                downCount = 0;
                peakCount = 0;
                total += 1;
            }

            else
            {
                upCount = 0;
                downCount += 1;
                total += downCount + 1 - (peakCount > downCount);
            }
        }

        return total;
    }
};