        vector<vector<int>> ans;
        if (n < 2) return ans;

        bool odd = (n % 2 == 1);
        int m = (odd ? n + 1 : n); 

        vector<int> teams(m);
        iota(teams.begin(), teams.end(), 0);

        int round_count = m - 1;

        for (int r = 0; r < round_count; r++) {
            for (int i = 0; i < m / 2; i++) {
                int a = teams[i];
                int b = teams[m - 1 - i];
                if (a < n && b < n) {
                    ans.push_back({a, b});
                }
            }
            rotate(teams.begin() + 1, teams.end() - 1, teams.end());
        }

        int sz = ans.size();

        for (int i = 0; i < sz; i++) {
            ans.push_back({ans[i][1], ans[i][0]});
        }

        return ans;