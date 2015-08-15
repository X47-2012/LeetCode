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
    void hasPathSumHelper(TreeNode* root, int num, int sum, vector<int> path, vector<vector<int> > &ans) {
        num = root->val + num;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == num) {
                ans.push_back(path);
            }
            return;
        }

        if (root->left != NULL)
            hasPathSumHelper(root->left, num, sum, path, ans);
        if (root->right != NULL)
            hasPathSumHelper(root->right, num, sum, path, ans);
    }

    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        vector<int> path;
        if (root == NULL) return ans;
        hasPathSumHelper(root, 0, sum, path, ans);
        return ans;
    }
};
