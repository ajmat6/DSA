class Solution {
public:
    // TC is O(nlogn) and sc is O(1)
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int low = 0;
        int high = tokens.size() - 1;
        int score = 0;
        int ans = 0;

        sort(tokens.begin(), tokens.end());
        while(low <= high) {
            if(power >= tokens[low]) {
                power -= tokens[low];
                score++;
                low++;
                ans = max(ans, score);
            }

            else if(score > 0) {
                power += tokens[high];
                score--;
                high--;
            }

            else break;
        }

        return ans;
    }
};