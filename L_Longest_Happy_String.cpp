class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a != 0) pq.push({a, 'a'});
        if(b != 0) pq.push({b, 'b'});
        if(c != 0) pq.push({c, 'c'});

        string ans = "";
        while(!pq.empty()) {
            auto [maxFreq, maxChar] = pq.top(); pq.pop();

            ans.push_back(maxChar);
            if(maxFreq >= 2) ans.push_back(maxChar);
            int remMaxFreq = maxFreq - min(2, maxFreq);

            if(pq.empty()) break;

            auto [smaxFreq, smaxChar] = pq.top(); pq.pop();
            ans.push_back(smaxChar);
            if(smaxFreq < remMaxFreq) smaxFreq -= 1;

            else {
                if(smaxFreq >= 2) {
                    ans.push_back(smaxChar);
                    smaxFreq -= 2;
                }
                else smaxFreq -= 1;
            }


            if(remMaxFreq > 0) pq.push({remMaxFreq, maxChar});
            if(smaxFreq > 0) pq.push({smaxFreq, smaxChar});
        }
        return ans;
    }
};