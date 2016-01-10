#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    queue<pair<TreeLinkNode *, int> > q;
    int currLevel = 0;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        pair<TreeLinkNode *, int> p = q.front();
        q.pop();
        if (!q.empty() && (p.second == q.front().second)) {
            p.first->next = q.front().first;
        }
        if (p.first->left != NULL) {
            q.push(make_pair(p.first->left, p.second + 1));
        }
        if (p.first->right != NULL) {
            q.push(make_pair(p.first->right, p.second + 1));
        }
    }
}

int main() {
    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);

    connect(root);
}
