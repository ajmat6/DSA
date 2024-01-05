class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& var, int target) {
        vector<int> ans;
        for(int i=0; i<var.size(); i++)
        {
            int a = var[i][0];
            int b = var[i][1];
            int c = var[i][2];
            int m = var[i][3];
            
            long long first = 1;
            while(b != 0)
            {
                if(b % 2 == 1) first *= a;
                a = (a * a) % 10;
                b = b / 2;
            }
            long long modulo = first % 10;
            
            
            long long second = 1; // a = modulo, power = c;
            while(c != 0)
            {
                if(c % 2 == 1) second *= modulo;
                modulo = (modulo * modulo) % m;
                c = c / 2;
            }
            long long secModulo = second % m;
            if(secModulo == target) ans.push_back(i);
        }
        
        return ans;
    }
};