/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/



class Solution 
{
    public:
    static bool cmp(Job& a, Job& b) {
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) { 
        int maxDeadLine = INT_MIN;
        for(int i=0; i<n; i++) {
            int deadLine = arr[i].dead;
            maxDeadLine = max(maxDeadLine, deadLine);
        }
        
        sort(arr, arr + n, cmp);
        
        // make array of maxDeadLine + 1 length. We will perform a job at last possible day.
        vector<int> slots(maxDeadLine + 1, -1);
        
        int totalProfit = 0;
        int totalJobs = 0;
        for(int i=0; i<n; i++) {
            int currProfit = arr[i].profit;
            int currDeadLine = arr[i].dead;
            
            // check the slots of deadLine:
            for(int j=currDeadLine; j>=1; j--) {
                if(slots[j] == -1) {
                    slots[j] = 1;
                    totalProfit += currProfit;
                    totalJobs += 1;
                    break;
                }
            }
        }
        
        return {totalJobs, totalProfit};
    } 
};