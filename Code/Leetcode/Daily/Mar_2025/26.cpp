class Solution {
public:
    int steps(vector<int> &arr, int &median, int &x) {
        int steps = 0;
        for (auto &cur : arr) {
            steps += abs(cur - median) / x;
        }
        return steps;
    }

    int minOperations(vector<vector<int>>& grid, int x) {
        //mod should be same for each element
        int mod = grid[0][0] % x;
        vector<int> arr;
        for (auto &row : grid) {
            for (auto &i : row) {
                if (i % x != mod) {
                    return -1;
                }
                arr.push_back(i);
            }
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        return steps(arr, arr[n / 2], x);
    }
};