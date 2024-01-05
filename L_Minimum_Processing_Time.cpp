class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        
        int index = 3;
        
        int ans = INT_MIN;
        for(int i=processorTime.size()-1; i>=0; i--)
        {
            ans = max(ans, processorTime[i] + tasks[index]);
            index = index + 4;
        }
        
        return ans;
    }
};