class Solution {
public:
    // pair<int, pair<int, int>> solve(TreeNode* root) {
    //     if(root == NULL) return {0, {0, 1}}; // {ans, {coinsLeft/coinsNeeded, sign(+ when coins left and -  when coins needed)}}
    //     if(root -> left == NULL && root -> right == NULL) {
    //         if(root -> val == 1) return {0, {0, 1}};
    //         else if(root -> val == 0) return {1, {1, -1}};
    //         else return {root -> val - 1, {root -> val - 1, 1}};
    //     }

    //     pair<int, pair<int, int>> leftt = solve(root -> left);
    //     pair<int, pair<int, int>> rightt = solve(root -> right);

    //     int coinsLeft = (leftt.second.first * leftt.second.second) + (rightt.second.first * rightt.second.second);
    //     if(root -> val == 0) coinsLeft -= 1;
    //     else coinsLeft += (root -> val - 1);
    //     int coinsMove = (leftt.first + rightt.first) + abs(coinsLeft);
    //     int sign = (coinsLeft >= 0) ? 1 : -1;
    //     pair<int, pair<int, int>> ans = {coinsMove, {abs(coinsLeft), sign}};
    //     return  ans;
    // }

    // int distributeCoins(TreeNode* root) {
    //     return solve(root).first;
    // }

    int ans = 0;
    int solve(TreeNode* root) {
        if(!root) return 0;

        int left = solve(root -> left);
        int right = solve(root -> right);
        ans += abs(left) + abs(right);
        return root -> val - 1 + left + right;
    }

    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};