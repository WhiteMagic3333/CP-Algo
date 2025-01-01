class Solution {
public:

    long long sum_rem(vector<bool> &vis, int x, vector<vector<int>>& adj_list, vector<int>& values, int k, int &ans) {
        long long sum = values[x] % k;
        vis[x] = true;
        for (auto &node : adj_list[x]) {
            if (!vis[node]) {
                sum = (sum + sum_rem(vis, node, adj_list, values, k, ans)) % k;
            }
        }
        ans += (sum == 0);
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        //asssuming root to be node 0
        //find the sum of all numbers for children to root and replace each node's value
        //by the sum of the subtree(including the node)
        //if sum till current element is divisible by k then ans++ (except for the root)
        vector<bool> vis(n, false);
        vector<vector<int>> adj_list(n + 1);
        for (auto &e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        int ans = 0;
        sum_rem(vis, 0, adj_list, values, k, ans);
        return ans;
    }
};