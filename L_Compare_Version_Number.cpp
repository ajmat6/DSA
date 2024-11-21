class Solution {
public:
    int compareVersion(string v1, string v2) {
        int index1 = 0, index2 = 0;
        int n1  = v1.size(), n2 = v2.size();

        while(index1 < n1 || index2 < n2) {
            int first = 0, second = 0;
            while(index1 < n1 && v1[index1] != '.') first = first * 10 + (v1[index1++] - '0');
            while(index2 < n2 && v2[index2] != '.') second = second * 10 + (v2[index2++] - '0');
            if(first < second) return -1;
            else if(first > second) return 1;
            index1++; index2++;
        }
        return 0;
    }
};