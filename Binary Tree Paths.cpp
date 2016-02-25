void binaryTreePathsHelper(TreeNode* root, string path, vector<string> &ans) {
    if (root == NULL) {
        return;
    }
    
    if (root->left == NULL && root->right == NULL) {
        string tmp = path + std::to_string(root->val);
        ans.push_back(tmp);
        return;
    }
    
    if (root->left != NULL) {
        string tmp = path + (std::to_string(root->val) + "->");
        binaryTreePathsHelper(root->left, tmp, ans);
    }
    
    if (root->right != NULL) {
        string tmp = path + (std::to_string(root->val) + "->");
        binaryTreePathsHelper(root->right, tmp, ans);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string path;
    binaryTreePathsHelper(root, path, ans);
    return ans;
}