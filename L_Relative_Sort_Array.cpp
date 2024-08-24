class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for(auto i: arr1) mp[i]++;

        int index = 0;
        for(auto i: arr2) {
            while(mp[i] != 0) {
                arr1[index++] = i;
                mp[i]--;
            }
        }

        vector<int> left;
        for(auto i: mp) {
            if(i.second != 0) {
                for(int j=0; j<i.second; j++) {
                    left.push_back(i.first);
                }
            }
        }

        sort(left.begin(), left.end());
        for(auto i: left) {
            arr1[index++] = i;
        }

        return arr1;
    }
};