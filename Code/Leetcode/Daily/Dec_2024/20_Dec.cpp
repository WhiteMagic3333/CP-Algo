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
    //dfs solution better

    //this is a good problem that also covers pricipal of divide and conquer
    //which is seem in binary search and dp problems


    void modify(TreeNode* left, TreeNode* right, int level) {
        if (left == NULL) {
            return;
        }
        if (level % 2) {
            swap(left->val, right->val);
        }
        modify(left->left, right->right, level + 1);
        modify(left->right, right->left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        modify(root->left, root->right, 1);
        return root;
    }
};