class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> sums;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            long long sum = 0;
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            sums.push(sum);
            if(sums.size() > k) sums.pop();
        }
        return sums.size() < k ? -1 : sums.top();
    }
};