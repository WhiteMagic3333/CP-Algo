class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> degree;
        vector<string> ans;
        for (int i = 0; i < rec.size(); i++) {
            degree[rec[i]] = ing[i].size();
            for (auto c_ing : ing[i]) {
                adj[c_ing].push_back(rec[i]);
            }
        }
        queue<string> q;
        for (auto s : sup) {
            if (adj.count(s) > 0) {
                q.push(s);
            }
        }
        while (q.size()) {
            auto cur = q.front();
            q.pop();
            for (auto u : adj[cur]) {
                degree[u]--;
                if (degree[u] == 0) {
                    ans.push_back(u);
                    q.push(u);
                }
            }
        }
        return ans;
    }
};