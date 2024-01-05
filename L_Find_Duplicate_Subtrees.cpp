class Solution {
public:
    // function to find values of a tree in depth first manner:
    void allValues(TreeNode* root, vector<int>& treeValues)
    {
        if(root == NULL)
        {
            treeValues.push_back(-999); // to represent value for null node
            return;
        }

        treeValues.push_back(root -> val);
        allValues(root -> left, treeValues);
        allValues(root -> right, treeValues);
    }

    // function to find all subtrees:
    void findAllSubtrees(TreeNode* root, vector<pair<TreeNode*, vector<int>>>& allSubtrees)
    {
        if(root == NULL) return;

        // finding all values of the subtree and storing it in the allSubtrees vector:
        vector<int> treeValues;
        allValues(root, treeValues);
        allSubtrees.push_back({root, treeValues});

        // left and right tree call:
        findAllSubtrees(root -> left, allSubtrees);
        findAllSubtrees(root -> right, allSubtrees);
    }

    string solve(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& ans)
    {
        if(root == NULL) return "";

        string temp = "";
        temp += to_string(root -> val) + "," + solve(root -> left, mp, ans) + "," + solve(root -> right, mp, ans);

        // if already there is same structure string in map of one time, then duplicate is found, if more than one then you have already stored in ans, otherwise duplcate is not found:
        if(mp[temp] == 1)
        {
            ans.push_back(root);
        }
        mp[temp]++;

        // store string in map:

        return temp;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // find all subtrees:
        // vector<pair<TreeNode*, vector<int>>> allSubtrees;

        // findAllSubtrees(root, allSubtrees);

        // // now we have all subtrees:
        // vector<TreeNode*> ans;

        // // as duplicate subtrees can be many, once a duplicate subtree is found, note it so that we dont take it up again:
        // set<vector<int>> vis;
        // for(int i=0; i<allSubtrees.size(); i++)
        // {
        //     for(int j=i+1; j<allSubtrees.size(); j++)
        //     {
        //         if(allSubtrees[i].second == allSubtrees[j].second && vis.find(allSubtrees[i].second) == vis.end()) // subtree found if two of them have equal structure of values:
        //         {
        //             ans.push_back(allSubtrees[i].first);
        //             vis.insert(allSubtrees[i].second); // storing subtree value structure to escape from duplicacy
        //         }
        //     }
        // }

        // return ans;

        // Approach 2nd: storing all subtrees and checking if its count is more than 1:
        unordered_map<string, int> mp;
        vector<TreeNode*> ans;
        solve(root, mp, ans);
        return ans;
    }
};