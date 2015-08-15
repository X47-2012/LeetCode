#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int leftHeight(TreeNode* root) {
    if (root == NULL)
        return 0;
    else
        return leftHeight(root->left) + 1;
}

int rightHeight(TreeNode* root) {
    if (root == NULL)
        return 0;
    else
        return rightHeight(root->right) + 1;
}

int countNodes(TreeNode* root) {
    if (root == NULL)
        return 0;
    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh) {
        return pow(2, lh) - 1;
    }

    if (leftHeight(root->right) + 1 == lh) {
        return pow(2, lh - 1) + countNodes(root->right);
    } else {
        return pow(2, rh - 1) + countNodes(root->left);
    }
}

int main() {

}


