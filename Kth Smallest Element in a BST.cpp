#include <iostream>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int treeSize(TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        return treeSize(root->left) + treeSize(root->right) + 1;
    }
}

int kthSmallest(TreeNode* root, int k) {
    int n = treeSize(root->left);
    if (n == k - 1) {
        return root->val;
    } else if (n > k - 1) {
        return kthSmallest(root->left, k);
    } else {
        return kthSmallest(root->right, k - n - 1);
    }
}


