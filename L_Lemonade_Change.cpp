class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for(int i=0; i<bills.size(); i++) {
            bills[i] == 5 ? five++ : bills[i] == 10 ? ten++ : twenty++;
            if(bills[i] == 5) continue;
            else if(bills[i] == 10) {
                if(!five) return false;
                five--;
            }
            else {
                if(five == 0) return false;
                if(ten == 0 && five < 3) return false;
                if(ten) {
                    ten--;
                    five--;
                }
                else five -= 3;
            } 
        }
        return true;
    }
};