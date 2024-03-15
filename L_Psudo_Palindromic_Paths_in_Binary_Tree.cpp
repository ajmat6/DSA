// using bit manipulation
class Solution {
public:
    // 1 -> odd freq
    // 0 -> even freq
    // each nos freq is tracked by its postion in binary format
    // TC is O(n) and SC is O(h)
    int solve(TreeNode* root, int bitmask) {
        if(!root) return 0;

        bitmask = bitmask ^ (1 << (root -> val)); // if any bit is set, odd freq, bit - 1 element's freq is odd
        // if only one element's freq is odd, then there is only one set bit and using kerninghans algo, it will give zero:
        if(!root -> left && !root -> right) return (bitmask & (bitmask - 1)) == 0 ? 1 : 0;
        return solve(root -> left, bitmask) + solve(root -> right, bitmask);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        // using dfs and freq count of each number from 1 to 9 for each leaf path from root:
        return solve(root, 0);
    }
};

// using freq array
class Solution {
public:
    // TC is O(n * 9) and SC is O(h)
    int solve(TreeNode* root, vector<int>& freq) {
        if(!root) return 0;
        if(!root -> left && !root -> right) {
            int odds = 0;
            freq[root -> val]++;
            for(auto i: freq) {
                if(i % 2 == 1) odds++;
            }
            freq[root -> val]--;
            if(odds <= 1) return 1;
            else return 0;
        }

        freq[root -> val]++;
        int total = solve(root -> left, freq) + solve(root -> right, freq);
        freq[root -> val]--;
        return total;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        // using dfs and freq count of each number from 1 to 9 for each leaf path from root:
        vector<int> freq(10);
        return solve(root, freq);
    }
};

// using stack
class Solution {
public:
    // TC is O(n) and SC is O(n)
    int pseudoPalindromicPaths (TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        int ans = 0;

        while(!st.empty()) {
            auto top = st.top(); st.pop();
            TreeNode* node = top.first;
            int parity = top.second;

            if(node) {
                parity = parity ^ (1 << (node -> val));
                if(node -> left == NULL && node -> right == NULL) {
                    if((parity & (parity - 1)) == 0) ans++;
                }

                else {
                    st.push({node -> right, parity});
                    st.push({node -> left, parity});
                }

            }

        }

        return ans;
    }
};