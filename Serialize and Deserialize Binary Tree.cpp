#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <stdlib.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string re = "[";
    if (root == NULL) {
        return re + ']';
    }

    queue<TreeNode *> q;
    vector<string> vec;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        if (node != NULL) {
            stringstream ss;
            ss << node->val;
            q.push(node->left);
            q.push(node->right);
            vec.push_back(ss.str());
        } else {
            vec.push_back("null");
        }
        q.pop();
    }

    int last_not_null = vec.size() - 1;
    while (vec[last_not_null] == "null") {
        last_not_null--;
    }
    for (int i = 0; i <= last_not_null; i++) {
        re += vec[i];
        if (i != last_not_null) {
            re += ',';
        }
    }
    return re + ']';
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data == "[]") {
        return NULL;
    }
    queue<TreeNode *> q;
    TreeNode *root = NULL;
    string num_str = "";
    bool flag = false;
    for (int i = 1; i < data.size(); i++) {
        if (data[i] != ',' && data[i] != ']') {
            num_str += data[i];
        } else {
            if (num_str != "null") {
                int num = atoi(num_str.c_str());
                TreeNode *node = new TreeNode(num);
                if (root == NULL) {
                    root = node;
                } else {
                    TreeNode *tmp = q.front();
                    if ((tmp->left == NULL) && (flag == false)) {
                        tmp->left = node;
                        flag = true;
                    } else {
                        tmp->right = node;
                        flag = false;
                        q.pop();
                    }
                }
                q.push(node);
            } else {
                TreeNode *tmp = q.front();
                if (flag == true) {
                    tmp->right = NULL;
                    flag = false;
                    q.pop();
                } else {
                    tmp->left = NULL;
                    flag = true;
                }
            }
            num_str = "";
        }
    }
    return root;
}

int main() {
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    string s = serialize(root);
    cout << s << endl;

    TreeNode *root1 = deserialize(s);
    s = serialize(root1);
    cout << s << endl;
}
