class Solution {
public:
    int solve(string& answerKey, int k, char TorF)
    {
        int i = 0, j = 0;
        int oppositeChar = 0;
        int ans = INT_MIN;

        while(j < answerKey.size())
        {
            // counting no of opposite characters in the sliding window of TorF character:
            if(answerKey[j] != TorF) oppositeChar++;

            // check that opposite char should not increase k in a sliding windoow of TorF character:
            while(i < j && oppositeChar > k)
            {
                char c = answerKey[i];

                if(c != TorF)
                {
                    oppositeChar--;
                }
                
                // increase i pointer to make a sliding window of required conditions:
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int trueWindow = solve(answerKey, k, 'T');
        int falseWindow = solve(answerKey, k, 'F');

        int ans = max(trueWindow, falseWindow);
        return ans;
    }
};