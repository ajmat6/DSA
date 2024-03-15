class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for(auto i: apple) total += i;
        
        sort(capacity.rbegin(), capacity.rend());
        int i = 0;
        for(i; i<capacity.size(); i++) {
            if(total > capacity[i]) total -= capacity[i];
            else break;
        }
        
        return i + 1;
    }
};