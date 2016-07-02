vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int> > path;
	if (root == NULL) {
		return path;
	}
	queue<TreeNode *> q;
	queue<int> l;
	q.push(root);
	l.push(0);
	int l_now = 0;
	
	vector<int> tmp;
	while (!q.empty()) {
		TreeNode *node = q.front();
		q.pop();
		int level = l.front();
		l.pop();
		
		if (level > l_now) {
			path.push_back(tmp);
			tmp.clear();
		}
		tmp.push_back(node->val);
		if (node->left != NULL) {
			q.push(node->left);
			l.push(level + 1);
		}
		if (node->right != NULL) {
			q.push(node->right);
			l.push(level + 1);
		}
		l_now = level;
	}
	if (tmp.size() != 0) {
		path.push_back(tmp);
	}
	reverse(path.begin(), path.end());
	return path;
}

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode *> q;
        TreeNode *flag = new TreeNode(-1);
        q.push(root);
        q.push(flag);
        vector<int> level;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node != flag) {
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                level.push_back(node->val);
            } else {
                result.push_back(level);
                level.erase(level.begin(), level.end());
                if (!q.empty()) q.push(flag);
            }
        }
        delete flag;
        flag = nullptr;
        reverse(result.begin(), result.end());
        return result;
    }
};