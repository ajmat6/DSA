// TC = O(logn) and SC = O(n)
class Solution {
public:
    TreeNode* solve(vector<int>& nums, int low, int high)
    {
        if(low > high) return nullptr;

        int mid = low + (high - low) / 2;
        int value = nums[mid];
        TreeNode* root = new TreeNode(value);
        root -> left = solve(nums, low, mid-1); 
        root -> right = solve(nums, mid+1, high); 

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};