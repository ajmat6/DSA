class Solution {
public:
    int maxScore(string s) {
        int ans = INT_MIN;
        for(int i=0; i<s.size()-1; i++)
        {
            string left = s.substr(0, i + 1);
            string right = s.substr(i + 1, s.size() - (i + 1));

            int zero = 0;
            int one = 0;
            for(int j=0; j<left.size(); j++)
            {
                if(left[j] == '0') zero++;
            }
            for(int j=0; j<right.size(); j++)
            {
                if(right[j] == '1') one++;
            }

            ans = max(ans, zero + one);
        }
        
        return ans;
    }
};