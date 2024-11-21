#include <bits/stdc++.h> 
using namespace std;

void dfs(BinaryTreeNode<int>* root) {
    if(root == nullptr) return;
    if(root -> left == nullptr && root -> right == nullptr) return;

    int left = 0, right = 0;
    if(root -> left) left = root -> left -> data;
    if(root -> right) right = root -> right -> data;

    int diff = root -> data - (left + right);
    if(diff > 0) {
        if(root -> left) root -> left -> data += diff;
        else root -> right -> data += diff;
    }

    dfs(root -> left);
    dfs(root -> right);

    // make equal:
    if(root -> left) left = root -> left -> data;
    if(root -> right) right = root -> right -> data;
    diff = root -> data - (left + right);
    root -> data += abs(diff);
    return;
}

void changeTree(BinaryTreeNode < int > * root) {
    dfs(root);
}  