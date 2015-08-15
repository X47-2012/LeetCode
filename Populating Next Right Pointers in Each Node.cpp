/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connectHelper(TreeLinkNode *leftNode, TreeLinkNode *rightNode) {
        leftNode->next = rightNode;
        if (leftNode->left != NULL && leftNode->right != NULL)
            connectHelper(leftNode->left, leftNode->right);
        if (rightNode->left != NULL && rightNode->right != NULL)
            connectHelper(rightNode->left, rightNode->right);
        if (leftNode->right != NULL && rightNode->left != NULL)
            connectHelper(leftNode->right, rightNode->left);
    }
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        if (root->left != NULL && root->right != NULL) connectHelper(root->left, root->right);
    }
};
