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
    bool hasPathSumHelper(TreeNode* root, int num, int sum) {
        num = root->val + num;
        if (root->left == NULL && root->right == NULL) {
            if (sum == num) {
                return true;
            } else {
                return false;
            }
        }

        if (root->left == NULL) return hasPathSumHelper(root->right, num, sum);
        if (root->right == NULL) return hasPathSumHelper(root->left, num, sum);
        return hasPathSumHelper(root->right, num, sum) | hasPathSumHelper(root->left, num, sum);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return hasPathSumHelper(root, 0, sum);
    }
};
