vector<TreeNode *> generateTreesHelper(int start, int end, vector<vector<vector<TreeNode *> > > &dp) {
    if (start > end) {
        return vector<TreeNode *>();
    } else if (dp[start][end].size() != 0) {
        return dp[start][end];
    } else {
        vector<TreeNode *> vec;
        vector<TreeNode *> rightVec = generateTreesHelper(start + 1, end, dp);
        vector<TreeNode *> leftVec = generateTreesHelper(start, end - 1, dp);
        
        for (int i = 0; i < rightVec.size(); i++) {
            TreeNode *head = new TreeNode(start);
            head->right = rightVec[i];
            vec.push_back(head);
        }
        
        for (int i = 0; i < leftVec.size(); i++) {
            TreeNode *head = new TreeNode(end);
            head->left = leftVec[i];
            vec.push_back(head);
        }
        
        for (int i = start + 1; i <= end - 1; i++) {
            vector<TreeNode *> leftVec = generateTreesHelper(start, i - 1, dp);
            vector<TreeNode *> rightVec = generateTreesHelper(i + 1, end, dp);
            for (int j = 0; j < leftVec.size(); j++) {
                for (int k = 0; k < rightVec.size(); k++) {
                    TreeNode *head = new TreeNode(i);
                    head->left = leftVec[j];
                    head->right = rightVec[k];
                    vec.push_back(head);
                }
            }
        }
        
        dp[start][end] = vec;
        return vec;
    }
}


vector<TreeNode*> generateTrees(int n) {
    vector<vector<vector<TreeNode *> > > dp(n + 1, vector<vector<TreeNode *> >(n + 1, vector<TreeNode *>()));
    for (int i = 1; i <= n; i++) {
        TreeNode *node = new TreeNode(i);
        dp[i][i].push_back(node);
    }
    return generateTreesHelper(1, n, dp);
}