class Solution{
public:
    int minimumDays(int S, int N, int M){
        int totalFood = S * M; // total food need to survive  S days
        int quotient = S / 7; // days on which you cant buy food
        int totalFoodBuyDays = S - quotient; // total days on which you can buy food
        
        int totalFoodBuy = totalFoodBuyDays * N; // total food you can buy
        if(totalFoodBuy < totalFood) return -1; 
        
        if(totalFood % N == 0) return totalFood / N;
        else return totalFood / N + 1;
    }
};