#include <iostream>
#include <string.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }else {
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
    }
}
