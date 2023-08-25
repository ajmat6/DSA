class Solution {
public:
    // function to find height of the tree:
    int findHeight(TreeNode* root)
    {
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL) return 0;

        int left = findHeight(root -> left);
        int right = findHeight(root -> right);

        return 1 + max(left, right);
    }

    void solve(TreeNode* root, int row, int col, int height, vector<vector<string>>& mat)
    {
        // Base Case:
        if(root == NULL) return;

        // if left child of curr node exist:
        if(root -> left)
        {
            // left child position:
            int nextRowIndex = row + 1;
            int nextColIndex = col - pow(2, height - row - 1);

            // placing in matrix:
            mat[nextRowIndex][nextColIndex] = to_string(root -> left -> val);

            // calling recursively:
            solve(root -> left, nextRowIndex, nextColIndex, height, mat);
        }

        // if right child of curr node exists:
        if(root -> right)
        {
            // right child position:
            int nextRowIndex = row + 1;
            int nextColIndex = col + pow(2, height - row - 1);

            mat[nextRowIndex][nextColIndex] = to_string(root -> right -> val);
            solve(root -> right, nextRowIndex, nextColIndex, height, mat);
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height = findHeight(root);
        cout << height;

        // 2d matrix creation:
        int rows = height + 1;
        int cols = pow(2, height + 1) - 1;
        vector<vector<string>> mat (rows, vector<string> (cols, ""));

        // root node add:
        mat[0][(cols - 1)/2] = to_string(root -> val);

        // calling recursively for the rest of the nodes:
        solve(root, 0, (cols-1)/2, height, mat);
        return mat;
    }
};