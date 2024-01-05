class Solution {
public:
    string reverseWords(string s) {
        // using two pointers:
        for(int left=0; left<s.size(); left++)
        {
            int right = left;

            // increasing right pointer till ' ' space is found:
            for(; right<s.size() && s[right] != ' '; right++)
            {
                
            }

            // reversing string b/w left and right pointers
            reverse(s.begin() + left, s.begin() + right);
            left = right;
        }

        return s;
    }
};