class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int miss;
        int repeat;
        
        for(int i=0; i<n; i++)
        {
            int pos = abs(arr[i]) - 1; // if arr[i] = 5 or -5 then we have to mark fourth index as vis (doing negative)
            if(arr[pos] < 0) repeat = abs(arr[i]);
            else arr[pos] *= -1;
        }
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] > 0)
            {
                miss = i + 1;
                break;
            }
        }
        
        return {repeat, miss};
    }
};
