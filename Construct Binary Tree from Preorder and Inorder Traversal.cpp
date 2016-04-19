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
    TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int l, int r, int &root_idx) {
        int root_val = preorder[root_idx];
        int i = l;
        for (; i <= r; i++) {
            if (inorder[i] == root_val) {
                break;
            }
        }
        TreeNode *root = new TreeNode(root_val);
        if (i - 1 >= l) {
            root->left = buildTreeHelper(preorder, inorder, l, i - 1, ++root_idx);  
        }
        if (i + 1 <= r) {
            root->right = buildTreeHelper(preorder, inorder, i + 1, r, ++root_idx);
        }
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return NULL;
        }
        int root_idx = 0;
        return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, root_idx);
    }
};