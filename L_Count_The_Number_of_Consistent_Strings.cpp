class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // int ans = 0;
        // vector<int> freq (26);
        // for(auto i: allowed) freq[i - 'a']++;

        // for(auto i: words) {
        //     int poss = 1;
        //     for(auto j: i) {
        //         if(freq[j - 'a'] == 0) {
        //             poss = 0;
        //             break;
        //         }
        //     }
        //     ans += poss;
        // }
        // return ans;



        // using bitManipulation:
        int bitStore = 0;
        for(auto i: allowed) {
            int mask = 1 << (i - 'a');
            bitStore |= mask;
        }

        int ans = 0;
        for(auto i: words) {
            int poss = 1;
            for(auto j: i) {
                int mask = 1 << (j - 'a');
                if(!(bitStore & mask)) {
                    poss = 0;
                    break;
                }
            }
            ans += poss;
        }
        return ans;
    }
};