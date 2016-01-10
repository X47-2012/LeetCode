struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int isBalancedHelper(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = isBalancedHelper(root->left);
    if (leftHeight == -1) {
        return -1;
    }
    
    int rightHeight = isBalancedHelper(root->right);
    if (rightHeight == -1) {
        return -1;
    }
    
    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
	if (isBalancedHelper(root) == -1) {
        return false;
    } else {
        return true;
    }
}