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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (cover(root->left, p) && cover(root->left, q)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (cover(root->right, p) && cover(root->right, q)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    
    bool cover(TreeNode *root, TreeNode *node) {
        if (root == NULL) {
            return false;
        }
        if (root == node) {
            return true;
        }
        return cover(root->left, node) || cover(root->right, node);
    }
};