class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        // finding which letter comes first in the words:
        vector<pair<int, int>> order;
        for(int i=0; i<N-1; i++)
        {
            int size = dict[i].size();
            int j = 0;
            while(j < size)
            {
                if(dict[i][j] == dict[i+1][j])
                {
                    j++;
                }
                
                else
                {
                    order.push_back({dict[i][j] - 'a', dict[i+1][j] - 'a'});
                    break;
                }
            }
        }
        
        // find indegree of all the characters:
        vector<int> indegree (K, 0);
        for(int i=0; i<order.size(); i++)
        {
            indegree[order[i].second]++;
        };
        
        // push zero indegree nodes into the queue:
        queue<int> q;
        for(int i=0; i<indegree.size(); i++)
        {
            if(indegree[i] == 0) q.push(i);
        }
        
        // Do BFS:
        vector<int> ans;
        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            
            // storing topo sort ans:
            ans.push_back(frontNode);
            
            // decrease indegree of the all nodes connected to frontNode:
            for(int i=0; i<order.size(); i++)
            {
                if(order[i].first == frontNode)
                {
                    indegree[order[i].second]--;
                    
                    if(indegree[order[i].second] == 0)
                    {
                        q.push(order[i].second);
                    }
                }
            }
        }
        
        // storing the ans in string:
        string finalAns = "";
        for(int i=0; i<ans.size(); i++)
        {
            char temp = 'a' + ans[i];
            finalAns.push_back(temp);
        }
        
        return finalAns;
    }
};