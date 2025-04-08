class Solution {
public:
    int minimumOperations(vector<int>& arr) {
        vector<int> freq(101, 0);
        int dis = 0, n = arr.size();
        for (int &i : arr) {
            dis += freq[i] == 0;
            freq[i]++;
        }
        int ans = 0, i = 0;
        while (dis < (n - i)) {
            for (int j = 0; j < 3 && i + j < n; j++) {
                freq[arr[i + j]]--;
                dis -= freq[arr[i + j]] == 0;
            }
            i += 3;
            ans++;
        }
        return ans;
    }
};