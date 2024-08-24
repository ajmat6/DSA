class Solution {
public:
    int numTeams(vector<int>& rating) {
        int maxi = 0;
        for(const int & i : rating){
            maxi = max(maxi,i);
        }
        vector<vector<int>> adj1(maxi+1),adj2(maxi+1);
        for(int i=0; i<rating.size(); i++){
            for(int j=i+1; j<rating.size(); j++){
                if(rating[i] > rating[j]){
                    adj1[rating[i]].push_back(rating[j]);
                }else if(rating[i] < rating[j]){
                    adj2[rating[i]].push_back(rating[j]);
                }
            }
        }
        int res = 0;
        for(const int & i : rating){
            for(const int & j : adj1[i])
                res += adj1[j].size();
            for(const int & j : adj2[i])
                res += adj2[j].size();
        }

        return res;
    }
};