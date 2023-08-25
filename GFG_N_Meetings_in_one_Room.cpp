class Solution
{
    public:
    static bool compare(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // making pairs of start and end timing and sorting them on the basis of end time:
        vector<pair<int, int>> sorted;
        
        for(int i=0; i<n; i++)
        {
            sorted.push_back({start[i], end[i]});
        }
        
        sort(sorted.begin(), sorted.end(), compare);
    
    
        int count = 1;
        int endIndex = sorted[0].second;
        
        for(int i=1; i<n; i++)
        {
            if(sorted[i].first > endIndex)
            {
                count++;
                endIndex = sorted[i].second;
            }
        }
        
        return count;
    }
};

