class Solution {
public:
    bool check(int number, vector<int>& temp, int k)
    {
        for(int i=0; i<temp.size(); i++)
        {
            if(number + temp[i] == k) return false;
        }
        
        return true;
    }
    
    int minimumSum(int n, int k) {
        if(n == 1) return 1;
        
        vector<int> temp;
        int count = 0;
        int num = 1;
        
        while(count < n)
        {
           bool checkNum = check(num, temp, k);
           if(checkNum)
           {
               temp.push_back(num);
               num++;
               count++;
           }
            
            else
            {
               num++; 
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) ans += temp[i];
        return ans;
    }
};