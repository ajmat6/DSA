class Solution {
    set<int> st;
    int rows;
    int cols;
    long long total;
public:
    Solution(int m, int n) {
        rows = m;
        cols = n;
        total = m * n;
    }
    
    vector<int> flip() {
        int index = rand() % total; // choosing a random index:

        // iterating untill we get a random index which is not flipped before:
        while(st.find(index) != st.end())
        {
            index = rand() % total;
        }

        // finding row and column no using index no:
        int row = index / cols;
        int col = index % cols;

        st.insert(index);
        return {row, col};
    }
    
    void reset() {
        st.clear();
    }
};