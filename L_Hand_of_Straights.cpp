class Solution {
public:
    bool solve(vector<int>& hand, int groupSize, int index) {
        int next = hand[index] + 1;
        int group = 1;
        hand[index] = -1; // it is used and already taken into consideration
        int currIndex = index + 1;
        while(currIndex < hand.size() && group < groupSize) {
            if(hand[currIndex] == next) {
                group += 1;
                next = hand[currIndex] + 1;
                hand[currIndex] = -1;

            }
            currIndex++;
        }
        return group == groupSize ? true : false;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // using hashmap: nlogn but insertion and fetching takes logn time which is taking more time
        // map<int, int> mp;
        // int mini = INT_MAX;
        // for(auto i: hand) {
        //     mp[i]++;
        //     mini = min(mini, i);
        // }

        // int curr = mp.begin() -> first; int group = 0;
        // while(mp.size() > 0) {
        //     if(mp.find(curr) != mp.end()) {
        //         mp[curr]--;
        //         if(mp[curr] == 0) mp.erase(curr);
        //         curr += 1;
        //         group += 1;

        //         if(group == groupSize) {
        //             group = 0;
        //             curr = mp.begin() -> first;
        //         }
        //     }
        //     else return false;
        // }
        // return group == 0 ? true : false;

        // using recursion: nlogn time but only once for sorting
        sort(hand.begin(), hand.end());
        for(int i=0; i<hand.size(); i++) {
            if(hand[i] >= 0 && !solve(hand, groupSize, i)) return false;
        }
        return true;
    }
};