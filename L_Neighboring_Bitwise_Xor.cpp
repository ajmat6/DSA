class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr = 0;
        for(auto &i: derived) xorr ^= i;
        return xorr == 0;
    }
};