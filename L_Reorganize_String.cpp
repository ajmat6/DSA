class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }

        // if any char has freq greater than (n+1)/2, where n is string length, then it is not possible to reorganize string:
        int len = s.size();
        int range = (len + 1) / 2;
        for(auto i: mp)
        {
            if(i.second > range) return "";
        }

        // rearranging string: using priority queue for storing max freq char at top:
        priority_queue<pair<int, char>> q;
        for(auto i: mp)
        {
            q.push({i.second, i.first});
        }

        int size = 0;
        string ans = "";
        while(size < len)
        {
            char a = q.top().second;
            ans.push_back(a);

            auto topElement = q.top();
            q.pop();
            topElement.first -= 1;
            size++;

            if(size != len)
            {
                char b = q.top().second;
                ans.push_back(b);

                auto secondTop = q.top();
                q.pop();
                secondTop.first--;
                q.push(secondTop);
                
                q.push(topElement);
                size++;
            }
        }

        return ans;
    }
};