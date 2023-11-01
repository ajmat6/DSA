class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // using property a ^ b = c, then b = a ^ c or c ^ a. Here a is xorTillNow and we have to find b. c is pref[i]
        vector<int> ans (pref.size());
        ans[0] = pref[0];

        int xorTillNow = ans[0];
        for(int i=1; i<pref.size(); i++)
        {
            ans[i] = pref[i] ^ xorTillNow;
            xorTillNow ^= ans[i];
        }

        return ans; // return
    }
};