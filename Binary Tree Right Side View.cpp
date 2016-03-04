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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        if (root == NULL) {
            return output;
        }
        queue<TreeNode *> q;
        TreeNode *fakeNode = new TreeNode(-1);
        
        q.push(root);
        q.push(fakeNode);
        
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
            if (!q.empty() && q.front() == fakeNode) {
                output.push_back(node->val);
                q.pop();
                q.push(fakeNode);
            }
        }
        
        return output;
    }
};