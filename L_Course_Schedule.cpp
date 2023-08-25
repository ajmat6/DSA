class Solution {
public:
    // Applying cycle detection in directed graphs using DFS:
    bool DFSCycle(int node, vector<int> prerequisites[], vector<bool>& isVisited, vector<bool>& DFSVisited)
    {
        isVisited[node] = true;
        DFSVisited[node] = true;

        for(int j=0; j<prerequisites[node].size(); j++)
        {
            int child = prerequisites[node][j];
            if(isVisited[child] && DFSVisited[child]) return true;

            if(!isVisited[child])
            {
                bool ans = DFSCycle(child, prerequisites, isVisited, DFSVisited);
                if(ans) return true;
            }
        }

        // backtrack DFSVisited:
        DFSVisited[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<bool> isVisited (numCourses, false);
        vector<bool> DFSVisited (numCourses, false);

        // Making adj list of course and dependent course:
        vector<int> graph [numCourses];
        for(int i=0; i<prerequisites.size(); i++)
        {
            int courseType = prerequisites[i][0];
            int courseDepend = prerequisites[i][1];

            graph[courseType].push_back(courseDepend);
        }

        // DFS Traversal:
        for(int i=0; i<numCourses; i++)
        {
            if(!isVisited[i])
            {
                bool ans = DFSCycle(i, graph, isVisited, DFSVisited);
                if(ans) return false;
            }
        }

        return true;
    }
};