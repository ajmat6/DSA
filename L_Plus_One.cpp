class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i=digits.size()-1; i>=0; i--)
        {
            if(digits[i] != 9)
            {
                digits[i] += 1;
                break;
            }

            else if(digits[i] == 9)
            {
                if(i == 0)
                {
                    digits[i] = 0;
                    carry = 1;
                    break;
                }
                
                else
                {
                    digits[i] = 0;
                }
            }
        }

        if(carry == 0) return digits;

        cout << digits[0];
        vector<int> ans;
        ans.push_back(1);
        for(auto i: digits) ans.push_back(i);
        return ans;
    }
};