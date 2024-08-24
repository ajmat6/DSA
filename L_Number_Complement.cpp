class Solution {
public:
    int findComplement(int num) {
        int count = 0;
        int temp = num;
        while(temp != 0) {
            temp = temp >> 1;
            count++;
        }

        int power = 0;
        int xorrNum = 0;
        for(int i=0; i<count; i++) {
            xorrNum += pow(2, power++);
        }
        return num ^ xorrNum;
    }
};