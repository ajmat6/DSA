// 2n total time for n calls and n space:
class StockSpanner {
private: stack<pair<int, int>> st;
public:
    StockSpanner() {}
    int next(int price) {
        if(st.empty() || st.top().first > price) {
            st.push({price, 1});
            return 1;
        }

        int ans = 0;
        while(!st.empty() && st.top().first <= price) {
            ans += st.top().second;
            st.pop();
        }
        st.push({price, ans + 1});
        return ans + 1;
    }
};