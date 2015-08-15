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
        if (root == NULL) {
            return root;
        }

        int lower = min(p->val, q->val);
        int higher = max(p->val, q->val);

        if ((root->val <= higher) && (root->val >= lower)) {
            return root;
        } else if (root->val < lower) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (root->val > higher) {
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};
