class Solution {
public:
    vector<vector<int>> ans;

    void DFS(vector<vector<int>>& graph, int node, vector<int>& temp)
    {
        if(node == graph.size() - 1)
        {
            temp.push_back(node);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        temp.push_back(node);
        for(auto i: graph[node])
        {
            int adjNode = i;
            DFS(graph, adjNode, temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        DFS(graph, 0, temp);
        return ans;
    }
};