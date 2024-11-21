class Solution {
public:
    TreeNode* makeTree(vector<int>& nums, int low, int high) {
        if(low > high) return nullptr;
        int mid = low + (high - low) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode -> left = makeTree(nums, low, mid - 1);
        newNode -> right = makeTree(nums, mid + 1, high);
        return newNode;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums, 0, nums.size() - 1);
    }
};