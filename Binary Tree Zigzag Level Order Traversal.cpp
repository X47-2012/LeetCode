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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
		if (root == nullptr) {
			return result;
		}
		queue<TreeNode *> q;
		TreeNode *flag = new TreeNode(-1);
		q.push(root);
		q.push(flag);
		vector<int> level;
        bool is_reverse = false;
		while (!q.empty()) {
			TreeNode *node = q.front();
			q.pop();
			if (node != flag) {
				if (node->left != nullptr) q.push(node->left);
				if (node->right != nullptr) q.push(node->right);
				level.push_back(node->val);
			} else {
                if (is_reverse == true) {
                    reverse(level.begin(), level.end());
                    is_reverse = false;
                } else {
                    is_reverse = true;
                }
				result.push_back(level);
				level.erase(level.begin(), level.end());
				if (!q.empty()) q.push(flag);
			}
		}
		delete flag;
		flag = nullptr;
		return result;
    }
};