/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* root, vector<int> &largest, int level) {
        if (root == NULL) {
            return;
        }
        if (largest.size() < level) {
            largest.push_back(root->val);
        } else {
            largest[level - 1] = max(largest[level - 1], root->val);
        }
        solve(root->left, largest, level + 1);
        solve(root->right, largest, level + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> largest;
        solve(root, largest, 1);
        return largest;
    }
};