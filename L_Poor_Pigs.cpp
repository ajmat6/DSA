class Solution {
public:
    bool checkPigs(int val, int buc, int mtd, int mtt)
    {
        // no of turns we have to check for poisnous bucket:
        int options = mtt / mtd;
        int onePigCheck = options + 1; // if there is one pig to check, it can check turns + 1 pigs alone

        long long int totalPigCheck = pow(onePigCheck, val); // therefore 'val' pigs can check (onePigcheck)^'val' buckets
        if(buc <= totalPigCheck) return true; // if buckets are less than total buckets 'val' pigs can check than 'val' pigs is possible ans
        else return false;
    }

    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // if(buckets == 1) return 0;

        // int low = 1;
        // int high = buckets; // max pigs required (one for each)
        // if(buckets > 5) high = 5; // power increase constraint for above function
        // int ans = buckets;

        // // binary search over min and max pigs possible
        // while(low <= high)
        // {
        //     int mid = low + (high - low) / 2;

        //     bool check = checkPigs(mid, buckets, minutesToDie, minutesToTest);
        //     if(check)
        //     {
        //         ans = min(ans, mid);
        //         high = mid - 1;
        //     }

        //     else
        //     {
        //         low = mid + 1;
        //     }
        // }

        // return ans;

        // same above logic without using any loops:
        int ans = 0;
        int onePigCheck = minutesToTest / minutesToDie + 1;
        int total;

        for(total=1; total<buckets; )
        {
            total = total * onePigCheck; // iterativly multiplying onePigCheck like combinations (1 * 5 * 5 * 5 if onePigCheck is 5)
            ans++;
        }

        return ans;
    }
};