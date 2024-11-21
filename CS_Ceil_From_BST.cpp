#include <bits/stdc++.h> 
using namespace std;

int findCeil(BinaryTreeNode<int> *root, int x){
    int ans = -1;
    while(root) {
        if(root -> data < x) root = root -> right;
        else {
            ans = root -> data;
            root = root -> left;
        }
    }
    return ans;
}