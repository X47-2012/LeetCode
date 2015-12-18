vector<int> inorderTraversal(TreeNode* root) {
     vector<int> path;
	 if (root == NULL) {
		 return path;
	 }
	 stack<TreeNode *> st;
	 while (!st.empty() || root) {
		 if (root) {
			 st.push(root);
			 root = root->left;
		 } else {
			 root = st.top();
			 st.pop();
			 path.push_back(root->val);
			 root = root->right;
		 }
	 }
	 return path;
}