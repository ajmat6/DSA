class Solution {
public:
    pair<int, int> solve(TreeNode* root, int& ans)
    {
        if(root == NULL) return {INT_MIN, INT_MAX};

        int nodeValue = root -> val;
        if(root -> left == NULL && root -> right == NULL) return {nodeValue, nodeValue};
        else
        {
            pair<int, int> leftt = solve(root -> left, ans);
            pair<int, int> rightt = solve(root -> right, ans);
            int minValue = min(leftt.second, rightt.second);
            int maxValue = max(leftt.first, rightt.first);
            int diff = max(abs(nodeValue - minValue), abs(nodeValue - maxValue));
            ans = max(ans, diff);
            return {max(nodeValue, maxValue), min(nodeValue,minValue)};
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};