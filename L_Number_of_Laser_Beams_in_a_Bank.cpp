class Solution {
public:
    int countOnes(string temp)
    {
        int count = 0;
        for(int j=0; j<temp.size(); j++)
        {
            if(temp[j] == '1')
            {
                count++;
            }
        }

        return count;
    }

    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int n = bank.size();
        int prev = countOnes(bank[0]);
        for(int i=1; i<n; i++)
        {
            int curr = countOnes(bank[i]);
            if(curr == 0) continue;
            else
            {
                ans += prev * curr;
                prev = curr;
            }
        }

        return ans;
    }
};