class Solution {
public:
    int max(int a, int b)
    {
        if(a >= b) return a;
        else return b;
    }
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        sort(hours.begin(), hours.end());
        int low = 0;
        int high = hours.size()-1;
        int ans = 0;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(hours[mid] >= target)
            {
                ans =  max(ans, hours.size() - mid);
                high = mid - 1;
            }
            
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};