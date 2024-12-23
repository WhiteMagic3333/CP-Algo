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
    #define pi pair<TreeNode*, int> 
    int minimumOperations(TreeNode* root) {
        queue<pi> q;
        q.push({root, 0});
        int ans = 0;
        while(q.size()) {
            set<pair<int, int>> pq;
            vector<int> cur_level;
            int level = q.front().second;
            while(q.size() && q.front().second == level) {
                TreeNode* node = q.front().first;
                if (node->left != NULL) {
                    q.push({node->left, level + 1});
                }
                if (node->right != NULL) {
                    q.push({node->right, level + 1});
                }
                cur_level.push_back((node->val));
                pq.insert({node->val, cur_level.size() - 1});
                q.pop();
            }
            for (int i = 0; i < cur_level.size(); i++) {
                auto expected = *pq.begin();
                if (expected.first != cur_level[i]) {
                    pq.insert({cur_level[i], expected.second});
                    pq.erase({cur_level[i], i});
                    swap(cur_level[i], cur_level[expected.second]);
                    ans++;
                }
                pq.erase(pq.begin());
            }
            cur_level.clear();
        }
        return ans;
    }
};