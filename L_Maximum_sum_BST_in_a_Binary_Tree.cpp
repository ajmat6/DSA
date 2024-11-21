class DS {
    public:
    int maxi;
    int mini;
    int sum;
    bool isBST;
};

class Solution {
public:
    // vector<int> find(TreeNode* root, int& ans) {
    //     if(root == nullptr) return {1, 0, INT_MAX, INT_MIN};

    //     vector<int> left = find(root -> left, ans);
    //     vector<int> right = find(root -> right, ans);

    //     vector<int> res (4);
    //     res[0] = 1;
    //     res[1] = root -> val + left[1] + right[1];
    //     res[2] = min(root -> val, left[2]);
    //     res[3] = max(root -> val, right[3]);

    //     if(left[0] && right[0] && root -> val > left[3] && root -> val < right[2]) ans = max(ans, res[1]);
    //     else res[0] = 0;
    //     return res;
    // }


    DS find(TreeNode* root, int& ans) {
        if(root == nullptr) return {INT_MIN, INT_MAX, 0, true};

        DS left = find(root -> left, ans);
        DS right = find(root -> right, ans);

        DS res;
        res.maxi = max(root -> val, right.maxi);
        res.mini = min(root -> val, left.mini);
        res.sum = root -> val + left.sum + right.sum;
        res.isBST = true;

        if(left.isBST && right.isBST && root -> val > left.maxi && root -> val < right.mini) ans = max(ans, res.sum);
        else res.isBST = false;
        return res;
    }

    int maxSumBST(TreeNode* root) {
        // using vectors:
        // int ans = 0;
        // find(root, ans);
        // return ans;


        // using class:
        int ans = 0;
        DS res = find(root, ans);
        return ans;
    }
};