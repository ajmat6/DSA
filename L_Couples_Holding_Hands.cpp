class DisjointSet
{
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0; i<parent.size(); i++)
        {
            parent[i] = i;
        }
    }

    int ultimateParent(int n)
    {
        if(parent[n] == n) return n;
        else return parent[n] = ultimateParent(parent[n]);
    }

    void unionBySize(int u, int v)
    {
        int ulpU = ultimateParent(u);
        int ulpV = ultimateParent(v);

        if(ulpU == ulpV) return;

        if(size[ulpU] > size[ulpV])
        {
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }

        else
        {
            parent[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        }
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;

        // Brute force -> O(n^2)
        // for(int i=0; i<row.size(); i+=2)
        // {
        //     // finding present and its reverse couple number:
        //     int couple = row[i];
        //     int reverseCouple;
        //     if(couple % 2 == 0) reverseCouple = couple + 1;
        //     else reverseCouple = couple - 1;

        //     // finding reverse couple index in row and swaping it:
        //     for(int j=i+1; j<row.size(); j++)
        //     {
        //         if(j == i+1 && row[j] == reverseCouple) break;
        //         if(row[j] == reverseCouple)
        //         {
        //             int temp = row[j];
        //             row[j] = row[i+1];
        //             row[i+1] = temp;
        //             ans++;
        //             break;
        //         }
        //     }
        // }

        // return ans;


        // Approach 2nd -> O(n)

        int n = row.size();
        
        // to store the group no of each couple:
        vector<int> parent (n, 0);

        // to actually play with group no of the couple, we need a vector:
        vector<int> actual;

        // map to map where each group couple lies in the row:
        unordered_map<int, vector<int>> mp;

        // assigning group no to each couple:
        int group = 1; // starting group no as 1:
        for(int i=0; i<parent.size(); i+=2)
        {
            parent[i] = group;
            parent[i+1] = group;
            group++;
        }

        // forming actual group vector:
        int index = 0;
        for(int i=0; i<row.size(); i+=2)
        {
            int u = row[i];
            int v = row[i+1];

            // if the adj couples group is not same, storing their index in mp map and pushing them into ans vector:
            if(parent[u] != parent[v])
            {
                actual.push_back(parent[u]);
                actual.push_back(parent[v]);

                // where each groups couple is lying if they are not together: this is not related to actual index
                mp[parent[u]].push_back(index);
                mp[parent[v]].push_back(index+1);

                index += 2;
            }
        }

        int swaps = 0;
        for(int i=0; i<actual.size(); i+=2)
        {
            if(actual[i] != actual[i+1])
            {
                swaps++;
                int value = actual[i+1];
                int newIndex = -1;

                // checking second couple's index in actual vector:
                if(mp[actual[i]][0] > i+1) // yahi he next couple ki index
                {
                    newIndex = mp[actual[i]][0];
                }

                else
                {
                    newIndex = mp[actual[i]][1];
                }

                // swap oppo couples:
                swap(actual[i+1], actual[newIndex]);

                // update the couples index in mp map:
                if(mp[value][0] == i + 1)
                {
                    mp[value][0] = newIndex;
                }

                // if(mp[value][1] == i + 1)
                else
                {
                    mp[value][1] = newIndex;
                }
            }
        }

        return swaps;


        // Approach 3rd using DSU:

        // int n = row.size();
        // DisjointSet ds(n);

        // // making union of every adj nodes:
        // for(int i=0; i<row.size(); i+=2)
        // {
        //     ds.unionBySize(row[i], row[i+1]);
        // }

        // // checking if every couple are in union or not:
        // int ans = 0;
        // for(int i=0; i<row.size(); i+=2)
        // {
        //     if(ds.ultimateParent(i) != ds.ultimateParent(i+1))
        //     {
        //         ans++;
        //         ds.unionBySize(ds.ultimateParent(i), ds.ultimateParent(i+1));
        //     }
        // }

        // return ans;
    }
};