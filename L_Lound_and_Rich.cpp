class Solution {
public:
    int DFS(vector<int>& quiet, unordered_map<int, list<int>>& adjList, int num, vector<int>& ans)
    {
        if(ans[num] != -1) return ans[num]; // memorisation:

        ans[num] = num; // assuming no one is richer than current person:
        for(auto i: adjList[num])
        {
            if(quiet[ans[num]] > quiet[DFS(quiet, adjList, i, ans)])
            {
                ans[num] = ans[i]; // using memorized value
            }
        }

        return ans[num];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // CReate Adjacancy list:
        // unordered_map<int, list<int>> adjList;
        // for(auto i: richer)
        // {
        //     int rich = i[0];
        //     int poor = i[1];

        //     adjList[poor].push_back(rich);
        // }

        //DFS:
        // vector<int> ans (quiet.size(), -1);
        // for(int i=0; i<quiet.size(); i++)
        // {
        //     ans[i] = DFS(quiet, adjList, i, ans);
        // }
 
        // return ans;

        vector<int> indegree (quiet.size(), 0);
        vector<int> ans (quiet.size());

        unordered_map<int, list<int>> adjList;
        for(auto i: richer)
        {
            int rich = i[0];
            int poor = i[1];

            adjList[rich].push_back(poor);
            indegree[poor]++;
        }

        queue<int> q;

        // pushing 0 degree nodes into the queue and assuming no one is quieter than them:
        for(int i=0; i<indegree.size(); i++)
        {
            ans[i] = i;
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // anyone who is pushed into the queue than its ans quiter is already found:
        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto i: adjList[front])
            {
                // as front is richer than its childs, then if its ans's quiteness is less than its child's current quietness, than update child's current quietness:
                if(quiet[ans[front]] < quiet[ans[i]])
                {
                    ans[i] = ans[front];
                }

                // decrease indegree: Jab zero indegree ho jaayega, then its ans is already found:
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }

        return ans;
    }
};