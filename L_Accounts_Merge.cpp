class Solution {
public:
    class DisjointSets 
    {
        vector<int> parent;
        vector<int> rank;

        public: 

        DisjointSets(int n)
        {
            parent.resize(n+1);
            rank.resize(n+1, 0);

            for(int i=0; i<parent.size(); i++) parent[i] = i;
        }

        int ultimateParent(int n)
        {
            if(parent[n] == n) return n;
            else return parent[n] = ultimateParent(parent[n]);
        }

        void UnionByRank(int u, int v)
        {
            int parentOfU = ultimateParent(u);
            int parentOfV = ultimateParent(v);

            if(rank[parentOfU] < rank[parentOfV])
            {
                parent[parentOfU] = parentOfV;
            }

            else if(rank[parentOfU] > rank[parentOfV])
            {
                parent[parentOfV] = parentOfU;
            }

            else
            {
                parent[parentOfU] = parentOfV;
                rank[parentOfV]++;
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // mapping of emails with their names in int form
        unordered_map<string, int> mp;

        DisjointSets ds(accounts.size());
        for(int i=0; i<accounts.size(); i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                // if the gmail already exist to be of someone, merge them:
                if(mp.find(accounts[i][j]) == mp.end())
                {
                    mp[accounts[i][j]] = i;
                }
                else
                {
                    int k = mp[accounts[i][j]];
                    ds.UnionByRank(i, k);
                }
            }
        }

        // make a list of same accounts emails with respect to integer by the help of map:
        vector<string> listt[accounts.size()];
        for(auto x: mp)
        {
            string mail = x.first;
            int prt = x.second;
            int ultParent = ds.ultimateParent(prt);

            listt[ultParent].push_back(mail);
        }

        // mapping of integer to account names of above data in sorted order:
        vector<vector<string>> ans;
        for(int i=0; i<accounts.size(); i++)
        {
            // if the given integer map does not have any gmials it means that account have been merged with other, so there is no need to return it ans:
            if(listt[i].size() == 0) continue;

            sort(listt[i].begin(), listt[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto x: listt[i])
            {
                temp.push_back(x);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};