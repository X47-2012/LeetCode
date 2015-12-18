
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
		this->root = root;
    	while (root != NULL) {
			st.push(root);
			root = root->left;
		}
	}

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
		root = st.top();
		st.pop();
		int val = root->val;
		root = root->right;
		while (root != NULL) {
			st.push(root);
			root = root->left;
		}
		return val;
    }

private:
	stack<TreeNode *> st;
	TreeNode *root;
};

int main() {
	BSTIterator i = BSTIterator(root);
	while (i.hasNext()) cout << i.next() << endl;
}