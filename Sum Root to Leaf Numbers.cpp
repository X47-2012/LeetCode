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
    int sumNumbersHelp(TreeNode* root, int num) {
        num = num * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            return num;
        } else if (root->left != NULL && root->right != NULL) {
            // �ݹ���ã���������ʱ��numֵ�ָ���ǰ״̬
            return sumNumbersHelp(root->left, num) + sumNumbersHelp(root->right, num);
        } else if (root->left != NULL) {
            return sumNumbersHelp(root->left, num);
        } else {
            return sumNumbersHelp(root->right, num);
        }
    }

    int sumNumbers(TreeNode* root) {
        if (root == 0) {
            return 0;
        }
        return sumNumbersHelp(root, 0);
    }
};
