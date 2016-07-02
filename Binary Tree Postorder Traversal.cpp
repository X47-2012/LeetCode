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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> stk;
        TreeNode *p = root, *q = nullptr;
        do {
            while (p != nullptr) {
                stk.push(p);
                p = p->left;
            }
            q = nullptr;
            while (!stk.empty()) {
                p = stk.top();
                stk.pop();
                if (p->right == q) {
                    result.push_back(p->val);
                    q = p;
                } else {
                    stk.push(p);
                    p = p->right;
                    break;
                }
            }
        } while (!stk.empty());
        return result;
    }
};