class Manacher {
    public:
    vector<int> p;
    void build(string& s) {
        // create hash string:
        string t;
        for(auto i: s) {
            t += string("#") + i;
        }
        t += "#";

        // p array creation:
        int n = t.size();
        p.resize(n, 1);
        int l = 1, r = 1;
        for(int i=1; i<n; i++) {
            if(l + r - i >= 0) p[i] = max(1, min(r - i, p[l + r - i]));
            while(i - p[i] >= 0 && i + p[i] < n && t[i - p[i]] == t[i + p[i]]) p[i]++;
            if(i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    int getLongestPalindrome(int center, bool odd) { // odd is true if around center you are looking for odd length longest palindrome
        int pos = 2 * center + 1 + (!odd); // if looking for even length, then add 1
        return p[pos] - 1;
    }

    bool isPalindrome(int low, int high) {
        if((high - low + 1) <= getLongestPalindrome((high + low) / 2, high%2 == low%2)) return true; // if low and high have same parity (both even and both odd), then it is odd length string that we are checking
        return false;
    }
};




// functional: faster
vector<int> p;
void build(string& s) {
    string t;
    for(auto i: s) {
        t += string("#") + i;
    }
    t += "#";

    int n = t.size();
    p.resize(n, 1);
    int l = 1, r = 1;
    for(int i=1; i<n; i++) {
        if(l + r - i >= 0) p[i] = max(1, min(r - i, p[l + r - i]));
        while(i - p[i] >= 0 && i + p[i] < n && t[i - p[i]] == t[i + p[i]]) p[i]++;
        if(i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
}

int getLongestPalindrome(int center, bool odd) { 
    int pos = 2 * center + 1 + (!odd); 
    return p[pos] - 1;
}

bool isPalindrome(int low, int high) {
    if((high - low + 1) <= getLongestPalindrome((high + low) / 2, high%2 == low%2)) return true; 
    return false;
}