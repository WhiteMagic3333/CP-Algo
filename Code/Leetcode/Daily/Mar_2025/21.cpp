class Solution {
public:

    void add(unordered_map<string, int> &str_node, string &cur, int &idx) {
        if (str_node[cur] != 0) {
            return;
        }
        str_node[cur] = idx;
        idx++;

    }

    void dfs(vector<vector<int>> &adj, vector<int> &pos, int i) {
        pos[i] = -1;
        if (adj[i].size()) {
            int cur_pos = 1;
            for (auto u : adj[i]) {
                if (pos[u] == 0) {
                    dfs(adj, pos, u);
                }
                if (pos[u] == -1) {
                    cur_pos = -1;
                    break;
                }
            }
            pos[i] = cur_pos;
        }
    }


    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> str_node; //convert string to a node
        int idx = 1;
        for (int i = 0; i < recipes.size(); i++) {
            add(str_node, recipes[i], idx);
            for (auto &ing : ingredients[i]) {
                add(str_node, ing, idx);
            }
        }
        int n = idx;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < recipes.size(); i++) {
            int u = str_node[recipes[i]];
            for (auto &ing : ingredients[i]) {
                int v = str_node[ing];
                adj[u].push_back(v);
            }
        }
        vector<int> pos(n + 1, 0);
        for (auto &s : supplies) {
            pos[str_node[s]] = 1;
        }
        vector<string> ans;
        for (auto &r : recipes) {
            int i = str_node[r];
            if (!pos[i]) {
                dfs(adj, pos, i);
            }
            if (pos[i] == 1) {
                ans.push_back(r);
            }
        }
        return ans;
    }
};