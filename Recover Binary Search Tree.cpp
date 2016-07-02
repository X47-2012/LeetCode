/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void maxLeft(TreeNode* root, TreeNode* &maxNode) {
        if (root == NULL) return;
        if (root->val > maxNode->val) {
            maxNode = root;
        }
        maxLeft(root->left, maxNode);
        maxLeft(root->right, maxNode);
    }

    void minRight(TreeNode* root, TreeNode* &minNode) {
        if (root == NULL) return;
        if (root->val < minNode->val) {
            minNode = root;
        }
        minRight(root->left, minNode);
        minRight(root->right, minNode);
    }


    void recoverTree(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* maxNode = root->left;
        TreeNode* minNode = root->right;

        maxLeft(root->left, maxNode);
        minRight(root->right, minNode);

        if (maxNode != NULL && minNode != NULL && maxNode->val > minNode->val) {
            swap(maxNode->val, minNode->val);
            return;
        }
        if (maxNode != NULL && maxNode->val > root->val) {
            swap(maxNode->val, root->val);
            return;
        }
        if (minNode != NULL && root->val > minNode->val) {
            swap(root->val, minNode->val);
            return;
        }
        recoverTree(root->left);
        recoverTree(root->right);
    }
};
