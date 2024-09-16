vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int xorr = 0;
    for(int i=0; i<A.size(); i++) {
        xorr ^= A[i];
        xorr ^= i + 1;
    }
    
    int bitMask;
    for(int i=0; i<=31; i++) {
        int mask = 1 << i;
        if(xorr & mask) {
            bitMask = mask;
            break;
        }
    }
    
    int set = 0;
    int unSet = 0;
    for(int i=0; i<A.size(); i++) {
        if(A[i] & bitMask) set ^= A[i];
        else unSet ^= A[i];
        
        if((i + 1) & bitMask) set ^= (i + 1);
        else unSet ^= (i + 1);
    }
    
    // set and unset contains the repeating and missing no but which is what is not known:
    for(int i=0; i<A.size(); i++) {
        if(A[i] == set) return {set, unSet};
    }
    return {unSet, set};
}
