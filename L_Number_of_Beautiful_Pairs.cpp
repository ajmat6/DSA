class Solution {
public:
    int gcd(int i, int j)
    {
        // Base Case:
        if(i == j) return i;
        
        if(i > j) return gcd(i-j, j);
        else return gcd(i, j-i);
    }
    
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                string s = to_string(nums[i]);
                int firstDigit = s[0] - '0';
                int lastDigit = nums[j] % 10;
                if(gcd(firstDigit, lastDigit) == 1) ans++;
            }
        }
        
        return ans;
    }
};