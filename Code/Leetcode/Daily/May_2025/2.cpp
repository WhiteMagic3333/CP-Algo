class Solution {
public:
    string pushDominoes(string dom) {
        queue<pair<int, char>> q;
        int n = dom.size();
        for (int i = 0; i < n; i++) {
            if (dom[i] != '.') {
                q.push({i , dom[i]});
            }
        }
        while (!q.empty()) {
            auto [idx, dir] = q.front();
            q.pop();
            if (dom[idx] >= 'a') {
                dom[idx] = dir;
            }
            int next_idx = (dir == 'L') ? idx - 1 : idx + 1;
            if (next_idx >= 0 && next_idx < n) {
                if (dom[next_idx] == '.') {
                    dom[next_idx] = dir + 32; //
                    q.push({next_idx, dir});
                } else if (dom[next_idx] == 'r') {
                    dom[next_idx] = '.';
                }
            }
        }
        return dom;
    }
};