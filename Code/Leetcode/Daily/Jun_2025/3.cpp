class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;
        int n = status.size();
        vector<bool> vis(n, false), pvis(n, false), hasKey(n, false);
        queue<int> q;
        for (int box : initialBoxes)
            q.push(box);
        while (!q.empty()) {
            int box = q.front();
            q.pop();
            if (status[box] == 0 && !hasKey[box]) {
                pvis[box] = true;
                continue;
            }
            if (!vis[box]) {
                vis[box] = true;
                ans += candies[box];
                for (int key : keys[box]) {
                    hasKey[key] = true;
                    if (pvis[key]) {
                        q.push(key);
                        status[key] = 1;
                    }
                }
                for (int contained : containedBoxes[box]) {
                    if (!vis[contained])
                        q.push(contained);
                }
            }
        }
        return ans;
    }
};