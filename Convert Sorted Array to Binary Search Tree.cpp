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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
        if (end < start) {
            return NULL;
        }
        if (start == end) {
            return new TreeNode(nums[start]);
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        } else {
            return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
        }
    }
};