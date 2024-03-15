class Solution {
public:
    int solve(vector<int>& bits, int index, int res) {
        int resLen = res >> 26;
        if(index == bits.size()) return resLen;

        int notTake = solve(bits, index + 1, res);
        int shift = (1 << 26) - 1;
        int oldChar = res & shift; // previous taken chars
        int newChar = bits[index] & shift; // curr index curr
        int newLen = bits[index] >> 26;
        int take = INT_MIN;
        if(!(oldChar & newChar)) { // if they don't have anything in common
            res = ((resLen + newLen) << 26) | (oldChar | newChar); // adding previously taken length with char word length  and taking the characters
            take = solve(bits, index + 1, res);
        }

        return max(take, notTake);
    }

    void stringToBits(string& word, unordered_set<int>& bitsStore) {
        int charBits = 0;
        for(auto i: word) {
            int mask = 1 << (i - 'a');
            if(mask & charBits) return; // don't add present string in checking as it has repeating chars
            charBits |= mask;
        }

        // last 5 bits can store the size of the word:
        int sizeBits = word.size() << 26;
        bitsStore.insert(charBits | sizeBits);
    }

    int maxLength(vector<string>& arr) {
        unordered_set<int> bitsStore;
        for(auto i: arr) stringToBits(i, bitsStore);
        vector<int> bits (bitsStore.begin(), bitsStore.end());
        return solve(bits, 0, 0);
    }
};