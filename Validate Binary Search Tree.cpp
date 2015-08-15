#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minTree(TreeNode *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->val;
}

int maxTree(TreeNode *root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->val;
}

bool isValidBST(TreeNode* root) {
    if (root == NULL) {
        return true;
    } else {
        bool left = true;
        if (root->left != NULL)
            left = isValidBST(root->left) && (maxTree(root->left) < root->val);

        if (left == false) return false;

        bool right = true;
        if (root->right != NULL)
            right = isValidBST(root->right) && (minTree(root->right) > root->val);
        return left & right;
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);
    cout << isValidBST(root);
}
