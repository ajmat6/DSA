/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int node, unordered_map<int, vector<pair<int, int>>>& adjList) {
        if(adjList.find(node) == adjList.end()) {
            TreeNode* newNode = new TreeNode(node);
            return newNode;
        }

        TreeNode* Node = new TreeNode(node);
        for(auto i: adjList[node]) {
            if(i.second) Node -> left = solve(i.first, adjList);
            else Node -> right = solve(i.first, adjList);
        }
        return Node;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        // hashmap + recursion solution:
        // unordered_map<int, vector<pair<int, int>>> adjList;
        // unordered_map<int, int> children;
        // for(auto i: des) {
        //     adjList[i[0]].push_back({i[1], i[2]});
        //     if(children.find(i[0]) == children.end() || children[i[0]] != 1) children[i[0]] = 0;
        //     children[i[1]] = 1;
        // }

        // // find head node:
        // int head = 0;
        // for(auto i: des) {
        //     if(children[i[0]] == 0) {
        //         head = i[0];
        //         break;
        //     }
        // }

        // return solve(head, adjList);

        // hashmap without recursion solution:
        unordered_map<int, TreeNode*> tree;
        unordered_set<int> children;

        for(auto i: des) {
            if(tree.find(i[0]) == tree.end()) {
                tree[i[0]] = new TreeNode(i[0]);
            }

            if(tree.find(i[1]) == tree.end()) {
                tree[i[1]] = new TreeNode(i[1]);
            }

            if(i[2]) tree[i[0]] -> left = tree[i[1]];
            else tree[i[0]] -> right = tree[i[1]];

            // insert into child:
            children.insert(i[1]);
        }

        // find head node:
        int head = 0;
        for(auto i: des) {
            if(children.find(i[0]) == children.end()) {
                head = i[0];
                break;
            }
        }
        return tree[head];
    }
};