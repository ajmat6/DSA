class Solution {
public:
    int timeRequiredToBuy(vector<int>& tic, int k) {
        // brute force:
        // int ans = 0;
        // while(true) {
        //     for(int i=0; i<tic.size(); i++) {
        //         if(tic[i] != 0) {
        //             ans += 1;
        //             tic[i] -= 1;
        //             if(i == k && tic[i] == 0) return ans;
        //         }
        //     }
        // }
        // return ans;


        // using min:
        int ans = 0;
        for(int i=0; i<tic.size(); i++) {
            int buy = i <= k ? tic[k] : tic[k] - 1;
            ans += min(tic[i], buy);
        }
        return ans;
    }
};