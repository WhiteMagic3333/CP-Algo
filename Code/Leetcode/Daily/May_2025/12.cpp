class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> f(10, 0);
        for (auto &i : digits) {
            f[i]++;
        }
        vector<int> ans;
        for (int i = 100; i < 1000; i += 2) {
            int a = i % 10, b = (i / 10) % 10, c = i / 100;
            f[a]--, f[b]--, f[c]--;
            if (min({f[a], f[b], f[c]}) >= 0) {
                ans.push_back(i);
            }
            f[a]++, f[b]++, f[c]++;
        }
        return ans;
    }
};