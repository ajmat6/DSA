/*
struct Item{
    int value;
    int weight;
};
*/


class Solution {
  public:
    double fractionalKnapsack(int w, Item arr[], int n) {
        // sorting according to value per weight:
        sort(arr, arr + n , [](Item& a, Item& b) {
            return a.value * 1.0 / a.weight > b.value * 1.0 / b.weight;
        });
        
        int totalW = 0;
        double totalValue = 0;
        for(int i=0; i<n; i++) {
            int currW = arr[i].weight;
            int currV = arr[i].value;
            
            if(totalW + currW <= w) {
                totalValue += currV;
                totalW += currW;
            }
            else {
                int remW = w - totalW;
                totalValue += (currV * remW * 1.0) / currW;
                break;
            }
        }
        return totalValue;
    }
};
