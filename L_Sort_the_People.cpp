class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> temp;
        for(int i=0; i<names.size(); i++) temp.push_back({heights[i], names[i]});
        sort(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); i++) names[i] = temp[temp.size()-1-i].second;
        return names;
    }
};