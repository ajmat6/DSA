class Solution {
public:
    int compareVersion(string v1, string v2) {
        int index1 = 0, index2 = 0;
        while(index1 < v1.size() || index2 < v2.size()) {
            long long val1 = 0, val2 = 0;
            while(index1 < v1.size() && v1[index1] != '.') val1 = val1 * 10 + v1[index1++] - '0'; 
            while(index2 < v2.size() && v2[index2] != '.') val2 = val2 * 10 + v2[index2++] - '0'; 
            index1++; index2++;

            if(val1 < val2) return -1;
            else if(val1 > val2) return 1;
        }

        return 0;
    }
};