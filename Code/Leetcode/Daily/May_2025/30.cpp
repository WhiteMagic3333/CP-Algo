class Solution {
public:
    void dfs(vector<int> &edges, int &i, vector<int> &dis) {
        if (edges[i] != -1 && dis[edges[i]] == -1) {
            dis[edges[i]] = dis[i] + 1;
            dfs(edges, edges[i], dis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        //dfs from node1 to all, and dfs from node2 to all and store their distances and keep the index at the min distance
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = edges.size();
        vector<int> d1(n, -1), d2(n, -1);
        d1[node1] = d2[node2] = 0;
        dfs(edges, node1, d1);
        dfs(edges, node2, d2);
        int ans = -1, mn = 1e9;
        for (int i = 0; i < n; i++) {
            if (min(d1[i], d2[i]) > -1 && max(d1[i], d2[i]) < mn) {
                mn = max(d1[i], d2[i]);
                ans = i;
            }
        }
        return ans;
    }
};