#include <bits/stdc++.h> 
using namespace std;

int floorInBST(TreeNode<int> * root, int X) {
    int ans = -1;
    while(root) {
        if(root -> val > X) root = root -> left;
        else {
            ans = root -> val;
            root = root -> right;
        }
    }
    return ans;
}