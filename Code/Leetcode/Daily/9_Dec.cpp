class Solution {
public:
    int parity(int a) {
        return a % 2;
    }

    vector<bool> isArraySpecial(vector<int>& arr, vector<vector<int>>& queries) {
        //stores the count of next consecutive numbers of alternating parity
        int n = arr.size();
        vector<int> sol(n, 1);
        for (int i =  n - 2; i >= 0; i--) {
            if (parity(arr[i]) != parity(arr[i + 1])) {
                sol[i] += sol[i + 1];
            }
        }
        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int sol_end = sol[start] + start - 1;
            ans.push_back(end <= sol_end);
        }
        return ans;
    }
};