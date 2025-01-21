class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n), col(m);
        int ans;
        vector<array<int, 2>> idx(n * m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                idx[mat[i][j]] = {i, j}; 
            }
        }
        for (int k = 0; k < arr.size(); k++) {
            auto &[i, j] = idx[arr[k]];
            row[i]++;
            col[j]++;
            if (row[i] == m || col[j] == n) {
                ans = k;
                break;
            }
        }
        return ans;
    }
};