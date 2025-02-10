class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26] = {0};
        for(auto &i: s) freq[i - 'a']++;
        priority_queue<int> pq;
        for(int i=0; i<26; i++) {
            if(freq[i] != 0) pq.push(i);
        }

        string ans = "";
        while(!pq.empty()) {
            int charIndex = pq.top(); pq.pop();
            int minTake = min(repeatLimit, freq[charIndex]);
            ans.append(minTake, 'a' + charIndex);
            freq[charIndex] -= minTake;

            if(freq[charIndex] == 0) continue; // next char move
            if(pq.empty()) break; // no next char

            int secondChar = pq.top(); pq.pop();
            ans += ('a' + secondChar);
            if(--freq[secondChar] != 0) pq.push(secondChar);
            pq.push(charIndex);
        }
        return ans;
    }
};