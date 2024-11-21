class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    int n = s.size();
		    for(int i=1; i<pow(2, n); i++) {
		        string temp = "";
		        for(int j=0; j<n; j++) {
		            if(i & (1 << (n - j - 1))) temp += s[j];
		        }
		        ans.push_back(temp);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};