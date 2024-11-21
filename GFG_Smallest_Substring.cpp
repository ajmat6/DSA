class Solution {
  public:
    string smallestSubstring(string str, int k) {
        int low = 0;
        int high = 0;
        int sum = 0;
        for(; high<k && high < str.size(); high++) {
            sum += str[high];
        }
        high--;
        
        int mini = INT_MAX;
        int start = -1;
        while(high < str.size()) {
            if(sum < mini) {
                mini = sum;
                start = low;
            }
            
            sum -= str[low];
            low++;
            high++;
            if(high < str.size()) sum += str[high];
        }
        
        return str.substr(start, k);
    }
};