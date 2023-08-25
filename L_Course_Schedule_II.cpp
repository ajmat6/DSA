class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // finding indegree of all courses:
        vector<int> indegree (numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++)
        {
            indegree[prerequisites[i][1]]++;
        }

        // push all 0 indegree nodes into the queue:
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

            // store in ans vector:
            ans.push_back(frontNode);

            // Decrease indegree of all nodes that is connected by frontNode:
            for(int i=0; i<prerequisites.size(); i++)
            {
                if(prerequisites[i][0] == frontNode)
                {
                    indegree[prerequisites[i][1]]--;
                    if(indegree[prerequisites[i][1]] == 0)
                    {
                        q.push(prerequisites[i][1]);
                    }
                }
            }
        }

        reverse(ans.begin(), ans.end());
        
        // if topo sort is not possible then return empty array:
        if(ans.size() != numCourses) return {};
        return ans;
    }
};