class Solution {
public:
    int countSetBits(int num) {
        int count = 0;
        while(num) {
            count++;
            num &= (num - 1);
        }
        return count;
    }

    int minimizeXor(int num1, int num2) {
        int totalSet1 = countSetBits(num1);
        int totalSet2 = countSetBits(num2);

        int shift = 0;
        while(totalSet1 != totalSet2) {
            int currShiftValue = 1 << shift;
            int setUnset = num1 & currShiftValue; 
            if(totalSet1 < totalSet2 && !setUnset) { // we have to set
                num1 |= currShiftValue;
                totalSet1++;
            }
            else if(totalSet1 > totalSet2 && setUnset) { // we have to unsert.
                num1 ^= currShiftValue;
                totalSet1--;
            }
            shift++;
        }
        return num1;
    }
};