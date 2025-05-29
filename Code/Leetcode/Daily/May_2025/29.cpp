class Solution {
public:
    int dfs(int i, int p, const vector<vector<int>> &al, vector<bool> &parity, bool even = true) {
        int targets = even;
        parity[i] = even;
        for (int j : al[i])
            if (j != p)
                targets += dfs(j, i, al, parity, !even);
        return targets;
    }
    vector<vector<int>> adjacencyList(vector<vector<int>>& edges) {
        vector<vector<int>> al(edges.size() + 1);
        for (auto &e: edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);            
        }        
        return al;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        int m = e1.size() + 1, n = e2.size() + 1;
        vector<bool> parity(m), ingnored(n);
        int even1 = dfs(0, -1, adjacencyList(e1), parity), odd1 = m - even1;
        int even2 = dfs(0, -1, adjacencyList(e2), ingnored), odd2 = n - even2;
        vector<int> res(m);
        for (int i = 0; i < m; ++i)
            res[i] = max(even2, odd2) + (parity[i] ? even1 : odd1);
        return res;
    }
};