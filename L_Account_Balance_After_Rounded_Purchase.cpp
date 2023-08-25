class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int rem;
        int quo;
        int deduct;
        
        rem = purchaseAmount % 10;
        quo = purchaseAmount / 10;
        
        if(rem >= 5)
        {
            deduct = 10 * quo + 10;   
        }
        
        else if(rem < 5)
        {
            deduct = 10 * quo;
        }
        
        return 100 - deduct;
    }
};