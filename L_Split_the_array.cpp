class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        set<int> st1;
        set<int> st2;
        
        for(auto i: nums) {
            if(st1.find(i) == st1.end()) st1.insert(i);
            else if(st2.find(i) == st2.end()) st2.insert(i);
            else return false;
        }
        
        return true;
    }
};