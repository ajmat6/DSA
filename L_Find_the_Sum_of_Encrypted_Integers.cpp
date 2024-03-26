class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums) {
            int element = i;
            int count = 0; int maxi = INT_MIN;
            while(element != 0) {
                maxi = max(maxi, element % 10);
                element /= 10;
                count++;
            }
            
            char c = '0' + maxi;
            string temp = "";
            temp.append(count, c);
            
            
            sum += stoi(temp);
        }
        
        return sum;
    }
};