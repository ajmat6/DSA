class Solution {
public:
    bool solve(int n, int turn)
    {
        for(int i=1; i<n; i++)
        {
            if(n % i == 0)
            {
                if(turn == 0) return solve(n - i, 1);
                else return solve(n - i, 0);
            }
        }

        if(turn == 0) return false;
        return true;
    }
    
    bool divisorGame(int n) {
        // return solve(n, 0);
        return n % 2 == 0;
    }
};