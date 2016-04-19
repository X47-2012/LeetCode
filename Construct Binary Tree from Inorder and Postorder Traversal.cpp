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
    TreeNode* buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int l, int r, int &root_idx) {
        int root_val = postorder[root_idx];
        int i = r;
        for (; i >= 0; i--) {
            if (inorder[i] == root_val) {
                break;
            }
        }
        
        TreeNode *root = new TreeNode(root_val);
        if (i + 1 <= r) {
            root->right = buildTreeHelper(inorder, postorder, i + 1, r, --root_idx);
        }
        if (i - 1 >= l) {
            root->left = buildTreeHelper(inorder, postorder, l, i - 1, --root_idx);
        }
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return NULL;
        }
        int root_idx = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, 0, root_idx, root_idx);
    }
};