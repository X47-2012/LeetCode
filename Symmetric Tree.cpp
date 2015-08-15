#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetricSub(TreeNode* rootLeft, TreeNode* rootRight) {
    if (rootLeft == NULL && rootRight == NULL)
        return true;
    if (rootLeft == NULL)
        return false;
    if (rootRight == NULL)
        return false;

    if (rootLeft->val != rootRight->val) {
        return false;
    } else {
        return isSymmetricSub(rootLeft->left, rootRight->right) && isSymmetricSub(rootLeft->right, rootRight->left);
    }
}

bool isSymmetric(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    else {
        isSymmetricSub(root->left, root->right);
    }
}

int main() {

}
