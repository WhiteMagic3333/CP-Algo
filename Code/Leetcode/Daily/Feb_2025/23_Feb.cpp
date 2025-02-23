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
    int i, j, n;
    void rec(TreeNode* root, vector<int> &pre, vector<int> &post) {
        if (i == n || j == n) {
            return;
        }
        if (root->val == post[j]) {
            j++;
            return;
        }
        if (i < n) {
            root->left = new TreeNode(pre[i++]);
            rec(root->left, pre, post);
            if (j < n && root->val == post[j]) {
                j++;
                return;
            }
            if (i < n) {
                root->right = new TreeNode(pre[i++]);
                rec(root->right, pre, post);
            }
            if (j < n && root->val == post[j]) {
                j++;
                return;
            }
        }
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode();
        root->val = pre[0];
        i = 1, j = 0, n = pre.size();
        rec(root, pre, post);
        return root;        
    }
};